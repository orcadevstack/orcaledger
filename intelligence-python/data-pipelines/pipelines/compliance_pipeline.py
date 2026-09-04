from data_pipelines.pipeline_base import DataPipeline
from data_pipelines.processors.compliance_processor import ComplianceProcessor

class CompliancePipeline(DataPipeline):
    name = "CompliancePipeline"

    def __init__(self):
        self.processor = ComplianceProcessor()

    def process(self, event):
        return self.processor.process(event)
