import time

class Scheduler:
    def schedule(self, func, interval):
        while True:
            func()
            time.sleep(interval)
