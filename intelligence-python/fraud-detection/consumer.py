from kafka import KafkaConsumer

consumer = KafkaConsumer("transactions", bootstrap_servers="kafka:9092")

for msg in consumer:
    print("Fraud engine received:", msg.value)
