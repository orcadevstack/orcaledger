FROM golang:1.22-alpine AS builder

WORKDIR /app
COPY . .

RUN go mod init service && go mod tidy
RUN go build -o service .

FROM alpine:latest
WORKDIR /app
COPY --from=builder /app/service .

EXPOSE 8080
CMD ["./service"]
