#include <iostream>
using namespace std;
// 作用：C++ 提供了初始化列表语法，用来初始化属性

// 语法：构造函数()：属性1(值1),属性2（值2）... {}
class Person
{
public:
    // 传统方式初始化
    //  Person(int a, int b, int c)
    //  {
    //      ma = a;
    //      mb = b;
    //      mc = c;
    //  }
    // 初始化列表方式初始化
    Person(int a, int b, int c) : ma(a), mb(b), mc(c)
    {
    }
    void PrintPerson()
    {
        cout << "mA:" << ma << endl;
        cout << "mB:" << mb << endl;
        cout << "mC:" << mc << endl;
    }

    int ma;
    int mb;
    int mc;
};
void test1()
{
    // Person p(10, 20, 30);
    Person p(30, 4, 65);
    p.PrintPerson();
}
int main()
{
    test1();
    return 0;
}