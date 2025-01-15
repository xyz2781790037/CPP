#include <iostream>
#include <vector>
using namespace std;
class Person
{
public:
    Person(string name,int age)
    {
        this->m_Age = age;
        this->m_Name = name;
    }
    string m_Name;
    int m_Age;
};
void test1()
{
    vector<Person> v;
    // 创建数据
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    Person p5("eee", 50);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    v.push_back(p4);
    v.push_back(p5);
    for (vector<Person>::iterator it = v.begin(); it != v.end();it++)
    {
        cout << "Name:" << it->m_Name << " Age:" << it->m_Age << endl;
    }
}
void test2()
{

    vector<Person *> v;

    // 创建数据
    Person p1("aaa", 10);
    Person p2("bbb", 20);
    Person p3("ccc", 30);
    Person p4("ddd", 40);
    Person p5("eee", 50);

    v.push_back(&p1);
    v.push_back(&p2);
    v.push_back(&p3);
    v.push_back(&p4);
    v.push_back(&p5);

    for (vector<Person *>::iterator it = v.begin(); it != v.end();it++)
    {
        // cout << "Name:" << (*it)->m_Name << "Age:" << (*it)->m_Age << endl;//the first way
        Person *p = (*it);
        cout << "Name:" << p->m_Name << " Age:" << (*it)->m_Age << endl;
    }
}
int main()
{
    test1();
    test2();
    return 0;
}