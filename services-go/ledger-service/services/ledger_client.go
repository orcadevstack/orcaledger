conn, _ := grpc.Dial("core-ledger:50051", grpc.WithInsecure())
client := pb.NewLedgerClient(conn)

resp, _ := client.PostTransaction(ctx, &pb.TransactionRequest{
	TxId:   "TX123",
	Debit:  100,
	Credit: 100,
})
