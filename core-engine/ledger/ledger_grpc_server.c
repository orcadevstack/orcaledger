#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "ledger.grpc-c.h"   // generated from ledger.proto
#include "ledger.h"          // your internal ledger API

static grpc_c_server_t *ledger_server;

/* Ctrl+C handler */
static void sigint_handler(int sig) {
    (void)sig;
    if (ledger_server) {
        grpc_c_server_destroy(ledger_server);
    }
    exit(0);
}

/* Callback invoked when PostTransaction RPC is called */
void ledger__LedgerService__PostTransaction_cb(grpc_c_context_t *context) {
    ledger__TransactionRequest *req;

    /* Read incoming request */
    if (context->gcc_stream->read(context, (void **)&req, 0, -1)) {
        fprintf(stderr, "Failed to read TransactionRequest\n");
        exit(1);
    }

    /* Call your internal ledger logic */
    int rc = post_transaction(req->tx_id, req->debit, req->credit);

    /* Build response */
    ledger__TransactionResponse resp;
    ledger__transaction_response__init(&resp);

    if (rc == 0) {
        resp.success = 1;
        resp.message = "Transaction posted successfully";
    } else {
        resp.success = 0;
        resp.message = "Failed to post transaction";
    }

    /* Write response */
    if (context->gcc_stream->write(context, &resp, 0, -1)) {
        fprintf(stderr, "Failed to write TransactionResponse\n");
        exit(1);
    }

    /* Finish RPC */
    grpc_c_status_t status;
    status.gcs_code = 0;  // OK

    if (context->gcc_stream->finish(context, &status, 0)) {
        fprintf(stderr, "Failed to finish RPC\n");
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

    /* Initialize gRPC-C */
    grpc_c_init(GRPC_THREADS, NULL);

    /* Create server */
    ledger_server = grpc_c_server_create(argv[1], NULL, NULL);
    if (!ledger_server) {
        fprintf(stderr, "Failed to create ledger gRPC server\n");
        exit(1);
    }

    /* Listen on TCP port */
    grpc_c_server_add_insecure_http2_port(ledger_server, "0.0.0.0:50051");

    /* Initialize LedgerService (generated function) */
    ledger__LedgerService__service_init(ledger_server);

    /* Start server */
    grpc_c_server_start(ledger_server);

    /* Block until shutdown */
    grpc_c_server_wait(ledger_server);

    return 0;
}
