import pkgutil
import importlib
from compliance_rules.rule_base import ComplianceRule

def load_rules():
    rules = []
    package = "compliance_rules.rules"

    for _, module_name, _ in pkgutil.iter_modules([package.replace('.', '/')]):
        module = importlib.import_module(f"{package}.{module_name}")
        for attr in dir(module):
            obj = getattr(module, attr)
            if isinstance(obj, type) and issubclass(obj, ComplianceRule) and obj is not ComplianceRule:
                rules.append(obj())
    return rules
