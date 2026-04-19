#include <iostream>
#include <mysql/mysql.h>
#include <string>
#include <unistd.h>
using namespace std;

const string host = "127.0.0.1"; 
const string user = "edison";
const string passwd = "QAZwsxedc123456.";
const string db = "ai_study_data";
const unsigned int port = 3306;


int main()
{
    MYSQL *myfd = mysql_init(nullptr);
    if (nullptr == myfd)
    {
        cerr << "init MySQL error" << endl;
        return 1;
    }
    cout << "init MySQL Success" << endl;


      // 连接
    if (nullptr == mysql_real_connect(myfd, host.c_str(), user.c_str(), passwd.c_str(), db.c_str(), port, nullptr, 0))
    {
        cerr << "connect MySQL error" << endl;
        return 2;
    }
    cout << "connect MySQL Success" << endl;

     string sql; // 定义sql语句

    while (true) // 模拟一个MySQL命令行操作
    {
        cout << "mysql> ";
        if (!getline(cin, sql) || sql == "quit") 
        {
            cout << "Bye bye" << endl;
            break;
        }
        int n = mysql_query(myfd, sql.c_str());
        if (0 == n)
            cout << "[" << sql << "] Operation success" << endl;
        else 
            cerr << "Operation failed: " << n << endl;
    } 
    mysql_close(myfd);
    return 0;
}
