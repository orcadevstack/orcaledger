#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "ledger.grpc-c.h"   // generated from ledger.proto
#include "ledger.h"
#include "db.h"

static grpc_c_server_t *ledger_server;

/* Ctrl+C handler */
static void sigint_handler(int sig) {
    (void)sig;
    if (ledger_server) {
        grpc_c_server_destroy(ledger_server);
    }
    exit(0);
}

/* RPC callback: PostTransaction */
void ledger__LedgerService__PostTransaction_cb(grpc_c_context_t *context) {
    ledger__PostTransactionRequest *req;

    /* Read incoming request */
    if (context->gcc_stream->read(context, (void **)&req, 0, -1)) {
        fprintf(stderr, "[gRPC] Failed to read PostTransactionRequest\n");
        exit(1);
    }

    printf("[gRPC] Received transaction: %s\n", req->tx_id);

    /* Call internal ledger logic */
    int rc = post_transaction(
        req->tx_id,
        req->debit_account,
        req->credit_account,
        req->amount
    );

    /* Build response */
    ledger__PostTransactionResponse resp;
    ledger__post_transaction_response__init(&resp);

    if (rc == 0) {
        resp.success = 1;
        resp.message = "Transaction posted successfully";
    } else {
        resp.success = 0;
        resp.message = "Failed to post transaction";
    }

    /* Write response */
    if (context->gcc_stream->write(context, &resp, 0, -1)) {
        fprintf(stderr, "[gRPC] Failed to write PostTransactionResponse\n");
        exit(1);
    }

    /* Finish RPC */
    grpc_c_status_t status;
    status.gcs_code = 0;

    if (context->gcc_stream->finish(context, &status, 0)) {
        fprintf(stderr, "[gRPC] Failed to finish RPC\n");
        exit(1);
    }
}

/* Main: start gRPC server */
int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <socket-path>\n", argv[0]);
        exit(1);
    }

    signal(SIGINT, sigint_handler);

    /* Initialize PostgreSQL */
    if (ledger_init_db("host=localhost dbname=orcaledger user=orca password=orca") != 0) {
        fprintf(stderr, "[LEDGER] Failed to initialize DB\n");
        exit(1);
    }

    /* Initialize gRPC-C */
    grpc_c_init(GRPC_THREADS, NULL);

    /* Create server */
    ledger_server = grpc_c_server_create(argv[1], NULL, NULL);
    if (!ledger_server) {
        fprintf(stderr, "[gRPC] Failed to create ledger server\n");
        exit(1);
    }

    /* Listen on TCP port */
    grpc_c_server_add_insecure_http2_port(ledger_server, "0.0.0.0:50051");

    /* Register LedgerService */
    ledger__LedgerService__service_init(ledger_server);

    /* Start server */
    grpc_c_server_start(ledger_server);

    /* Block until shutdown */
    grpc_c_server_wait(ledger_server);

    return 0;
}
