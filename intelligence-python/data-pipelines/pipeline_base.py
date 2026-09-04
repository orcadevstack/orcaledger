class DataPipeline:
    name = "BasePipeline"

    def process(self, event):
        raise NotImplementedError
