#include <iostream>
#include <sqlite3.h>
#include "do_insert.h"
using namespace std;
#define DATABASE "student.db"

int main() {
    sqlite3 *db;
    char *errmsg;
    int cmd;
    if (sqlite3_open(DATABASE, &db) != SQLITE_OK){
        printf("%s\n", sqlite3_errmsg(db));
        return -1;
    } else{
        cout << "Open DATABASE Success." << endl;
    }
    //创建一张数据库的表格
    if (sqlite3_exec(db, "create table student(id Integer, name char, score Integer)", NULL, NULL, &errmsg) != SQLITE_OK)
    {
        cout << errmsg << endl;
    } else{
        cout << "create table or open success." << endl;
    }
    while (1){
        cout << "******************************************" << endl;
        cout << "1:insert 2:delete 3:query 4:update 5:quit." << endl;
        cout << "******************************************" << endl;
        scanf("%d", &cmd);
        switch (cmd) {
            case 1:
                do_insert(db);
                break;
            case 2:
                //do_delete();
                break;
            case 3:
                //do_query();
                break;
            case 4:
                //do_update();
                break;
            case 5:
                sqlite3_close(db);
                break;
            default:
                cout << "Error cmd! " << endl;
        }
    }
    return 0;
}
