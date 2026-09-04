import time

def retry(func, attempts=3):
    for _ in range(attempts):
        try:
            return func()
        except Exception:
            time.sleep(1)
    raise Exception("Retry failed")
