import grpc
import ledger_pb2_grpc

class GrpcGateway:
    def __init__(self):
        channel = grpc.insecure_channel("localhost:50051")
        self.ledger = ledger_pb2_grpc.LedgerServiceStub(channel)
