#include <stdio.h>
#include "db.h"

int db_init(OrcaDb *db, const char *conninfo) {
    db->conn = PQconnectdb(conninfo);
    if (PQstatus(db->conn) != CONNECTION_OK) {
        fprintf(stderr, "[DB] Connection failed: %s\n", PQerrorMessage(db->conn));
        return -1;
    }
    printf("[DB] Connected to PostgreSQL\n");
    return 0;
}

void db_close(OrcaDb *db) {
    if (db->conn) {
        PQfinish(db->conn);
        db->conn = NULL;
        printf("[DB] Connection closed\n");
    }
}

int db_exec(OrcaDb *db, const char *sql) {
    PGresult *res = PQexec(db->conn, sql);
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        fprintf(stderr, "[DB] Exec failed: %s\n", PQerrorMessage(db->conn));
        PQclear(res);
        return -1;
    }
    PQclear(res);
    return 0;
}

PGresult *db_query(OrcaDb *db, const char *sql) {
    PGresult *res = PQexec(db->conn, sql);
    if (PQresultStatus(res) != PGRES_TUPLES_OK) {
        fprintf(stderr, "[DB] Query failed: %s\n", PQerrorMessage(db->conn));
        PQclear(res);
        return NULL;
    }
    return res;
}

int db_prepare(OrcaDb *db, const char *stmt_name, const char *sql, int nParams) {
    PGresult *res = PQprepare(db->conn, stmt_name, sql, nParams, NULL);
    if (PQresultStatus(res) != PGRES_COMMAND_OK) {
        fprintf(stderr, "[DB] Prepare failed: %s\n", PQerrorMessage(db->conn));
        PQclear(res);
        return -1;
    }
    PQclear(res);
    return 0;
}

PGresult *db_exec_prepared(OrcaDb *db,
                           const char *stmt_name,
                           int nParams,
                           const char * const *paramValues,
                           const int *paramLengths,
                           const int *paramFormats,
                           int resultFormat) {
    PGresult *res = PQexecPrepared(db->conn, stmt_name,
                                   nParams, paramValues,
                                   paramLengths, paramFormats,
                                   resultFormat);
    if (PQresultStatus(res) != PGRES_TUPLES_OK &&
        PQresultStatus(res) != PGRES_COMMAND_OK) {
        fprintf(stderr, "[DB] Exec prepared failed: %s\n", PQerrorMessage(db->conn));
        PQclear(res);
        return NULL;
    }
    return res;
}
