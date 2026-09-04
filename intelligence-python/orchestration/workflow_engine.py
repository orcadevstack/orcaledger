from orchestration.registry import WORKFLOW_REGISTRY

class WorkflowEngine:
    def execute(self, workflow_name, event):
        workflow = WORKFLOW_REGISTRY[workflow_name]
        return workflow().run(event)
