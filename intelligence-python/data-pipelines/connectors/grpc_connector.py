import grpc
import ledger_pb2
import ledger_pb2_grpc

class GrpcConnector:
    def __init__(self):
        channel = grpc.insecure_channel("localhost:50051")
        self.stub = ledger_pb2_grpc.LedgerServiceStub(channel)

    def post_transaction(self, tx):
        return self.stub.PostTransaction(tx)
