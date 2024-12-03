#include <iostream>
#include <string>
using namespace std;
// 1、构造函数分类
//  按照参数分类分为 有参和无参构造   无参又称为默认构造函数
//  按照类型分类分为 普通构造和拷贝构造
class Person
{
public:
    // 无参（默认）构造函数
    Person()
    {
        cout << "无参构造函数!" << endl;
    }
    // 有参构造函数
    Person(int a)
    {
        age = a;
        cout << "有参构造函数!" << endl;
    }
    // 拷贝构造函数
    Person(const Person &p)
    {
        age = p.age;
        cout << "拷贝构造函数!" << endl;
    }
    // 析构函数
    ~Person()
    {
        cout << "析构函数!" << endl;
    }

public:
    int age;
};
void test1()
{
    Person p1;
    Person p2(10);
}
int main()
{
    test1();
    return 0;
}