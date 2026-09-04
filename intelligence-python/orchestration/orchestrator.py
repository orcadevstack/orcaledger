from orchestration.event_router import EventRouter
from orchestration.workflow_engine import WorkflowEngine

class Orchestrator:
    def __init__(self):
        self.router = EventRouter()
        self.engine = WorkflowEngine()

    def handle_event(self, event):
        workflow = self.router.route(event)
        return self.engine.execute(workflow, event)
