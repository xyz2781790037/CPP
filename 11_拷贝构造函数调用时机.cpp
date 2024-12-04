#include <iostream>
#include <string>
using namespace std;
class Person
{
public:
    Person()
    {
        cout << "无参构造函数!" << endl;
        mAge = 0;
    }
    Person(int age)
    {
        cout << "有参构造函数!" << endl;
        mAge = age;
    }
    Person(const Person &p)
    {
        cout << "拷贝构造函数!" << endl;
        mAge = p.mAge;
    }
    // 析构函数在释放内存之前调用
    ~Person()
    {
        cout << "析构函数!" << endl;
    }

public:
    int mAge;
};
// 使用一个已经创建完毕的对象来初始化一个新对象
void test1()
{
    Person p1(20);
    Person p2(p1);
    cout << p2.mAge << endl;
}
// 值传递的方式给函数参数传值
void dowork(Person p)
{
}
void test2()
{
    Person p;
    dowork(p);
}
// 以值方式返回局部对象
Person doWork2()
{
    Person p1;
    cout << (int *)&p1 << endl;
    return p1;
} // 本来应该有拷贝，编译器优化了，需要
// $ g++ 11_拷贝构造函数调用时机.cpp -fno-elide-constructors 
void test3()
{
    Person p = doWork2();
    cout << (int *)&p << endl;
}
int main()
{
    // test1();
    test3();
    return 0;
}