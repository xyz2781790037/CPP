#include <iostream>
using namespace std;
// 常函数：
// 成员函数后加const后我们称为这个函数为常函数
// 常函数内不可以修改成员属性
// 成员属性声明时加关键字mutable后，在常函数中依然可以修改
// 常对象：
// 声明对象前加const称该对象为常对象
// 常对象只能调用常函数
class Person
{
public:
    Person()
    {
        // m_A = 0;
        // m_B = 0;
    }
    // this指针的本质是一个指针常量，指针的指向不可修改
    // 如果想让指针指向的值也不可以修改，需要声明常函数
    void ShowPerson() const //->const Person* const this;
    {
        // const Type* const pointer;
        // this = NULL; //不能修改指针的指向 Person* const this;
        // this->mA = 100; //但是this指针指向的对象的数据是可以修改的

        // const修饰成员函数，表示指针指向的内存空间的数据不能修改，除了mutable修饰的变量
        this->m_B = 100;
    }

    void MyFunc() const
    {
        // mA = 10000;
    }

public:
    int m_A;
    mutable int m_B; // 可修改 可变的
};
void test1()
{
    Person p;
    p.ShowPerson();
}
void test2()
{
    const Person p; // 常量对象
    cout << p.m_A << endl;
    // p.m_A = 100;//常对象不能修改成员变量的值,但是可以访问
    p.m_B = 100; //但是常对象可以修改mutable修饰成员变量
    //常对象访问成员函数
	p.MyFunc(); //常对象不能调用const的函数
}
int main()
{
    test2();
    return 0;
}