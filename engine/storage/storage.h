#ifndef STORAGE_H
#define STORAGE_H

#include <stdbool.h>

#define MAX_NAME_LENGTH 64
#define MAX_ROWS 100
#define MAX_TABLES 100
#define MAX_DATE_LENGTH 10

typedef enum {
    INTEGER,
    STRING,
    FLOAT,
    ARRAY,
    DICTIONARY,
    DATE
} ColumnType;

typedef struct {
    char name[MAX_NAME_LENGTH];
    ColumnType type;
    int array_size;  // Used only if type is ARRAY
} Column;

typedef struct {
    Column columns[MAX_NAME_LENGTH];
    int column_count;
} Schema;

typedef struct {
    void* data[MAX_NAME_LENGTH];
    int column_count;
} Row;

typedef struct {
    char name[MAX_NAME_LENGTH];
    Schema schema;
    Row rows[MAX_ROWS];
    int row_count;
} Table;

typedef struct {
    char name[MAX_NAME_LENGTH];
    Table tables[MAX_TABLES];
    int table_count;
} Database;

Database* createDatabase(const char* name);
Table* createTable(Database* db, const char* table_name);
bool insertRow(Table* table, const void* data[]);
void printTable(const Table* table);
void updateRowById(Table* table, int index, const void* data[]);
void deleteRowById(Table* table, int index);
void freeTable(Table* table);
void freeDatabase(Database* db);
const Row* getRowById(const Table* table, int index);

#endif
