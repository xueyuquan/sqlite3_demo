//
// Created by xueyq on 11/7/22.
//

#include "do_delete.h"

int do_delete(sqlite3 * db){
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

    sprintf(sql, "insert into student values(%d, '%s', %d)", id, name, score);//键盘输入字符，并进行拼接
    if (sqlite3_exec(db, sql, NULL, NULL,&errmsg) != SQLITE_OK)
    {
        printf("%s\n",errmsg);
    } else{
        printf("Insert done.\n");
    }
    return 0;
}