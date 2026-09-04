from orchestration.workflows.transaction_workflow import TransactionWorkflow
from orchestration.workflows.settlement_workflow import SettlementWorkflow
from orchestration.workflows.compliance_workflow import ComplianceWorkflow
from orchestration.workflows.credit_scoring_workflow import CreditScoringWorkflow
from orchestration.workflows.fraud_detection_workflow import FraudDetectionWorkflow

WORKFLOW_REGISTRY = {
    "transaction_workflow": TransactionWorkflow,
    "settlement_workflow": SettlementWorkflow,
    "compliance_workflow": ComplianceWorkflow,
    "credit_scoring_workflow": CreditScoringWorkflow,
    "fraud_detection_workflow": FraudDetectionWorkflow,
}
