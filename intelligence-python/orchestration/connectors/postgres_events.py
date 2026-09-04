import psycopg2

class PostgresEvents:
    def __init__(self, conninfo):
        self.conn = psycopg2.connect(conninfo)

    def fetch_new(self):
        cur = self.conn.cursor()
        cur.execute("SELECT * FROM events ORDER BY created_at DESC LIMIT 50")
        return cur.fetchall()
