from data_pipelines.pipeline_base import DataPipeline
from data_pipelines.processors.credit_score_processor import CreditScoreProcessor

class CreditScoringPipeline(DataPipeline):
    name = "CreditScoringPipeline"

    def __init__(self):
        self.processor = CreditScoreProcessor()

    def process(self, event):
        return self.processor.process(event)
