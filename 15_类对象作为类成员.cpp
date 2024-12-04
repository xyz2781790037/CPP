#include <iostream>
using namespace std;
// C++ 类中的成员可以是另一个类的对象，我们称该成员为 对象成员
// class A {};
// class B
// {
//     A a;
// };
class Phone
{
public:
    Phone(string pname)
    {
        m_pname = pname;
        cout << "Phone构造" << endl;
    }
    ~Phone()
    {
        cout << "Phone析构" << endl;
    }

    string m_pname;
};
class Person
{
public:
    // Phone m_phone = pname;
    Person(string name, string pname) : m_name(name), m_phone(pname)
    {
        cout << "Person构造" << endl;
    }
    ~Person()
    {
        cout << "Person析构" << endl;
    }
    string m_name;
    Phone m_phone;
};
void test1()
{
    // 当类中成员是其他类对象时，我们称该成员为 对象成员
    // 构造的顺序是 ：先调用对象成员的构造，再调用本类构造
    // 析构顺序与构造相反
    Person p("张三", "苹果X");
    cout << p.m_name << "get" << p.m_phone.m_pname << endl;
    
}
int main()
{
    test1();
    return 0;
}