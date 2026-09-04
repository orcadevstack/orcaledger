from data_pipelines.pipeline_base import DataPipeline
from data_pipelines.processors.transaction_processor import TransactionProcessor

class TransactionPipeline(DataPipeline):
    name = "TransactionPipeline"

    def __init__(self):
        self.processor = TransactionProcessor()

    def process(self, event):
        return self.processor.process(event)
