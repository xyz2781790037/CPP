#include <iostream>
using namespace std;
// C++允许一个类继承多个类
// 语法： class 子类 ：继承方式 父类1 ， 继承方式 父类2...
// 多继承可能会引发父类中有同名成员出现，需要加作用域区分
class Base1
{
public:
    Base1()
    {
        m_A = 100;
    }

public:
    int m_A;
};

class Base2
{
public:
    Base2()
    {
        m_A = 200; // 开始是m_B 不会出问题，但是改为mA就会出现不明确 -> 二义性
    }

public:
    int m_A;
};
// 语法：class 子类：继承方式 父类1 ，继承方式 父类2
class Son : public Base2, public Base1
{
public:
    Son()
    {
        m_C = 300;
        m_D = 400;
    }

public:
    int m_C;
    int m_D;
};
void test1()
{
    Son s;
    cout << "sizeof Son = " << sizeof(s) << endl;
    cout << s.Base1::m_A << endl;
    cout << s.Base2::m_A << endl;
}
int main()
{
    test1();
    return 0;
}