#include <mysqlx/xdevapi.h>   // 最重要的头文件
#include <iostream>
#include <string>

#include <unistd.h>    //provide usleep(),Sleep().

using namespace mysqlx;       // 官方推荐使用这个命名空间

int main()
{
    int p = 0;
    try
    {
        std::cout << "MYSQL_CONCPP_VERSION_NUMBER = " << MYSQL_CONCPP_VERSION_NUMBER << std::endl;
        // 方式1：最推荐的连接字符串方式（类似 URI）
        Session sess("mysqlx://root:788826@localhost:33060");

        // 方式2：分开写参数（比较清晰）
        // Session sess("localhost", 33060, "root", "你的密码");

        // 方式3：带默认Schema（数据库名）
        // Session sess("mysqlx://root:你的密码@localhost:33060/testdb");

        std::cout << "连接成功！\n" << std::endl;

        // 获取或创建数据库（Schema）
        Schema db = sess.createSchema("ai_study_data", true);   // true = 如果不存在就创建
        // 等价写法： Schema db = sess.getSchema("mydb", true);

        std::cout << "使用数据库： " << db.getName() << "\n";

        // 创建一个文档集合（类似 MongoDB 的 collection）
        Collection coll = db.createCollection("user2", true);

        std::cout << "集合创建/获取成功： " << coll.getName() << "\n";

        // coll.add(
        //     R"({"id":0, "name":"Grok", "age":2, "telephone":11555})"
        // ).execute();

        // 马上关闭（养成好习惯）
        int i = 0;
        usleep(1000*1000*5);
        sess.close();
    }
    catch (const mysqlx::Error &err)
    {
        std::cout << "连接失败： " << err << "\n";
        return 1;
    }
    catch (std::exception &ex)
    {
        std::cout << "标准异常： " << ex.what() << "\n";
        return 1;
    }

    return 0;
}