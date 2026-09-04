from kafka import KafkaConsumer

class KafkaEvents:
    def __init__(self):
        self.consumer = KafkaConsumer("events", bootstrap_servers="localhost:9092")

    def listen(self):
        for msg in self.consumer:
            yield msg.value
