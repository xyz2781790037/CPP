#include <iostream>
using namespace std;
// 浅拷贝：简单的赋值拷贝操作

// 深拷贝：在堆区重新申请空间，进行拷贝操作
// 编译器自己会提供浅拷贝操作
class Person
{
public:
    // 无参（默认）构造函数
    Person()
    {
        cout << "无参构造函数!" << endl;
    }
    // 有参构造函数
    Person(int age, int height)
    {

        cout << "有参构造函数!" << endl;

        m_age = age;
        m_height = new int(height);
    }
    // 拷贝构造函数
    Person(const Person &p)
    {
        cout << "拷贝构造函数!" << endl;
        // 如果不利用深拷贝在堆区创建新内存，会导致浅拷贝带来的重复释放堆区问题
        m_age = p.m_age;
        // 深拷贝
        m_height = new int(*p.m_height);
    }

    // 析构函数
    ~Person()
    {
        // 对堆区数据进行释放操作
        cout << "析构函数!" << endl;
        if (m_height != NULL)
        {
            delete m_height;
        }
    }

public:
    int m_age;
    int *m_height;
};
void test1()
{
    Person p1(18, 160);
    cout << p1.m_age << " " << *p1.m_height << endl;
    Person p2(p1);
    cout << p2.m_age << " " << *p2.m_height << endl;
}
int main()
{
    test1();
    return 0;
}
// 总结：如果属性有在堆区开辟的，一定要自己提供拷贝构造函数，防止浅拷贝带来的问题