#include <iostream>
using namespace std;
class Base
{
public:
    Base()
    {
        m_A = 100;
    }
    void func()
    {
        cout << "Base - func()调用" << endl;
    }
    void func(int a)
    {
        cout << "Base - func(int a)调用" << endl;
    }
public:
    int m_A;
};
class Son : public Base
{
public:
    Son()
    {
        m_A = 20;
    }
    // 当子类与父类拥有同名的成员函数，子类会隐藏父类中所有版本的同名成员函数
    // 如果想访问父类中被隐藏的同名成员函数，需要加父类的作用域
    void func()
    {
        cout << "Son - func()调用" << endl;
    }

public:
    int m_A;
};
void test1()
{
    Son s;
    cout << "Son下的m_A = " << s.m_A << endl;
    // 当子类与父类拥有同名的成员函数，子类会隐藏父类中同名成员函数，加作用域可以访问到父类中同名函数
    cout << "Base下的m_A = " << s.Base::m_A << endl;
}
void test2()
{
    Son s;
    s.func();
    s.Base::func();
    s.Base::func(10);
}
int main()
{
    // test1();
    test2();
    return 0;
}