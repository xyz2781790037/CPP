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
    // 注意1：调用无参构造函数不能加括号，如果加了编译器认为这是一个函数声明
    // Person p1();
    // 括号法
    Person p2(10);
    Person p3(p2);
    // cout << p3.age << endl;
    // 显式法
    Person p4 = Person(10);
    Person p5 = Person(p2);
    // Person(10) 单独写就是匿名对象  当前行结束之后，马上析构
    // 不能利用 拷贝构造函数 初始化匿名对象 编译器认为是对象声明
    // Person p5(p4);
    // 隐式转换法
    Person p4 = 10; // Person p4 = Person(10);
    Person p5 = p4; // Person p5 = Person(p4);
}
int main()
{
    test1();
    return 0;
}