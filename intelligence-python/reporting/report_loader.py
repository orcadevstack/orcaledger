import pkgutil
import importlib
from reporting.report_base import ReportBase

def load_reports():
    registry = {}
    package = "reporting.generators"

    for _, module_name, _ in pkgutil.iter_modules([package.replace('.', '/')]):
        module = importlib.import_module(f"{package}.{module_name}")
        for attr in dir(module):
            obj = getattr(module, attr)
            if isinstance(obj, type) and issubclass(obj, ReportBase) and obj is not ReportBase:
                registry[obj.name] = obj
    return registry
