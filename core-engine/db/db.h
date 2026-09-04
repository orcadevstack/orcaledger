#ifndef ORCA_DB_H
#define ORCA_DB_H

#include <libpq-fe.h>
#include <stdint.h>

typedef struct {
    PGconn *conn;
} OrcaDb;

/* Initialize connection: "host=... dbname=... user=... password=..." */
int db_init(OrcaDb *db, const char *conninfo);

/* Close connection */
void db_close(OrcaDb *db);

/* Simple exec (no result set) */
int db_exec(OrcaDb *db, const char *sql);

/* Exec with result (caller processes PGresult and then PQclear) */
PGresult *db_query(OrcaDb *db, const char *sql);

/* Helpers for prepared statements (optional) */
int db_prepare(OrcaDb *db, const char *stmt_name, const char *sql, int nParams);
PGresult *db_exec_prepared(OrcaDb *db,
                           const char *stmt_name,
                           int nParams,
                           const char * const *paramValues,
                           const int *paramLengths,
                           const int *paramFormats,
                           int resultFormat);

#endif
