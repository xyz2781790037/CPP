#include <iostream>
using namespace std;
// 局限性：  模板的通用性并不是万能的
// 例如：
// template <class T>
// void f(T a, T b)
// {
//     a = b;
// }
// 在上述代码中提供的赋值操作，如果传入的a和b是一个数组，就无法实现了
// template <class T>
// void f(T a, T b)
// {
//     if (a > b)
//     {
//         ...
//     }
// }
// 在上述代码中，如果T的数据类型传入的是像Person这样的自定义数据类型，也无法正常运行
// 因此C++为了解决这种问题，提供模板的重载，可以为这些特定的类型提供具体化的模板
class Person
{
public:
    Person(string name, int age)
    {
        m_Name = name;
        m_Age = age;
    }
    string m_Name;
    int m_Age;
};
// 普通函数模板
template <class T>
bool myCompare(T &a, T &b)
{
    if (a == b)
    {
        return true;
    }
    else
    {
        return false;
    }
}
// 具体化，显示具体化的原型和定意思以template<>开头，并通过名称来指出类型
// 具体化优先于常规模板
template <>
bool myCompare(Person &p1, Person &p2)
{
    if (p1.m_Name == p2.m_Name && p1.m_Age == p2.m_Age)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void test1()
{
    int a = 10;
    int b = 10;
    // 内置数据类型可以直接使用通用的函数模板
    bool ret = myCompare(a, b);
    if (ret)
    {
        cout << "a == b" << endl;
    }
    else
    {
        cout << "a != b" << endl;
    }
}
void tset2()
{
    Person p1("Tom", 10);
    Person p2("Tom", 10);
    // 自定义数据类型，不会调用普通的函数模板
    // 可以创建具体化的Person数据类型的模板，用于特殊处理这个类型
    bool ret = myCompare(p1, p2);
    if (ret)
    {
        cout << "p1 == p2 " << endl;
    }
    else
    {
        cout << "p1 != p2 " << endl;
    }
}
int main()
{
    test1();
    return 0;
}
// 利用具体化的模板，可以解决自定义类型的通用化
// 学习模板并不是为了写模板，而是在STL能够运用系统提供的模板