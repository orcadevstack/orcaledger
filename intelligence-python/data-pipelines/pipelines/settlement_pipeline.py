from data_pipelines.pipeline_base import DataPipeline
from data_pipelines.processors.settlement_processor import SettlementProcessor

class SettlementPipeline(DataPipeline):
    name = "SettlementPipeline"

    def __init__(self):
        self.processor = SettlementProcessor()

    def process(self, event):
        return self.processor.process(event)
