//
// Created by xueyq on 10/31/22.
//
#include "do_insert.h"
int do_insert(sqlite3 * db){
    int id;
    char name[32] = {};
    int score;
    char sql[128] = {};
    char *errmsg;

    cout << "Input id:" << endl;
    scanf("%d", &id);
    getchar();

    cout << "Input name:" << endl;
    scanf("%s", name);
    getchar();

    cout << "Input score:" << endl;
    scanf("%d", &score);
    getchar();

    sprintf(sql, "insert into student values(%d, '%s', %d):", id, name, score);
    if (sqlite3_exec(db, sql, NULL, NULL,&errmsg) != SQLITE_OK)
    {
        printf("%s\n",errmsg);
    } else{
        printf("Insert done.\n");
    }
    return 0;
}