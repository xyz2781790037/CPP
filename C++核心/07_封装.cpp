#include <iostream>
#include <string>
using namespace std;
// 求圆周长
const double pi = 3.14;
class Circle
{
    // 访问权限
    // 公共权限
public:
    // 属性
    int m_r;
    double calculateZC()
    {
        return 2 * pi * m_r;
    }
};
class student
{
public:
    string name;
    int id;

public:
    void dd(string name);
};
class Person
{
public: // 类内可以访问，类外可以
    string m_name;

protected: // 类内可以访问，类外不可以]
    string m_car;

private: // 类内可以访问，类外不可以
    int m_password;

public:
    void func()
    {
        m_name = "zyx";
        m_car = "baoam";
        m_password = 12345;
    }
};
class c1
{
    int a;//默认为private
};
struct c3
{
    int a;//默认为public
};
int main()
{
    // Circle cl;
    // cl.m_r = 10;
    // cout << cl.calculateZC() << endl;
    // student st;
    // cin >> st.name;
    // cin >> st.id;
    // cout << st.name << endl;
    // cout << st.id << endl;
    Person p1;
    p1.m_name = "sf";
    // p1.m_car = "d";不可访问
    c1 c2;
    c3 c4;
    //c2.a = 3;->error
    c4.a = 4;
    return 0;
}