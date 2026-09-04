import psycopg2

class PostgresConnector:
    def __init__(self, conninfo):
        self.conn = psycopg2.connect(conninfo)

    def fetch_transactions(self):
        cur = self.conn.cursor()
        cur.execute("SELECT * FROM ledger_entries ORDER BY created_at DESC LIMIT 100")
        return cur.fetchall()
