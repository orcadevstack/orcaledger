from kafka import KafkaProducer, KafkaConsumer

class KafkaConnector:
    def __init__(self):
        self.producer = KafkaProducer(bootstrap_servers="localhost:9092")
        self.consumer = KafkaConsumer("transactions", bootstrap_servers="localhost:9092")

    def publish(self, topic, data):
        self.producer.send(topic, data.encode())
