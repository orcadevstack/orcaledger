from data_pipelines.pipeline_loader import load_pipelines

class PipelineEngine:
    def __init__(self):
        self.pipelines = load_pipelines()

    def run(self, event):
        for pipeline in self.pipelines:
            pipeline.process(event)
