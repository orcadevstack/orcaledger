import pkgutil
import importlib
from data_pipelines.pipeline_base import DataPipeline

def load_pipelines():
    pipelines = []
    package = "data_pipelines.pipelines"

    for _, module_name, _ in pkgutil.iter_modules([package.replace('.', '/')]):
        module = importlib.import_module(f"{package}.{module_name}")
        for attr in dir(module):
            obj = getattr(module, attr)
            if isinstance(obj, type) and issubclass(obj, DataPipeline) and obj is not DataPipeline:
                pipelines.append(obj())
    return pipelines
