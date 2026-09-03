package main

import (
    "log"
    "net/http"
)

func main() {
    mux := http.NewServeMux()

    mux.HandleFunc("/health", func(w http.ResponseWriter, r *http.Request) {
        w.WriteHeader(http.StatusOK)
        _, _ = w.Write([]byte("kyc-service service healthy"))
    })

    log.Println("kyc-service service running on :8080")
    log.Fatal(http.ListenAndServe(":8080", mux))
}
