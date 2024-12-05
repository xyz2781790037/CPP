#include <iostream>
using namespace std;
// 静态成员就是在成员变量和成员函数前加上关键字static，称为静态成员\

// 静态成员变量
// 所有对象共享同一份数据
// 在编译阶段分配内存
// 类内声明，类外初始化

// 静态成员函数
// 所有对象共享同一个函数
// 静态成员函数只能访问静态成员变量
class Person
{
public:
    // 静态成员变量特点：
    // 1 在编译阶段分配内存
    // 2 类内声明，类外初始化
    // 3 所有对象共享同一份数据
    static int ma; // 静态成员变量
private:
    static int mb;
};
int Person ::ma = 100;
int Person ::mb = 200;
void test1()
{
    Person p;
    cout << p.ma << endl;
    Person p2;
    p2.ma = 200;
    cout << p.ma << endl;
}
void test2()
{
    // 静态成员变量两种访问方式

    // 1、通过对象
    Person p1;
    p1.ma = 100;
    cout << "p1.m_A = " << p1.ma << endl;
    Person p2;
    p2.ma = 200;
    cout << "p1.m_A = " << p1.ma << endl; // 共享同一份数据
    cout << "p2.m_A = " << p2.ma << endl;
    // 2、通过类名
    cout << "m_A = " << Person::ma << endl;
    // cout << "m_B = " << Person::m_B << endl; //私有权限访问不到
}
int main()
{
    test1();
    return 0;
}