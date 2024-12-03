#include <iostream>
#include <string>
using namespace std;
//  构造函数
//  构造函数，没有返回值也不写void
//  函数名称与类名相同
//  构造函数可以有参数，因此可以发生重载
//  程序在调用对象时候会自动调用构造，无须手动调用,而且只会调用一次
class Person
{
public:
    Person()
    {
        cout << "Person的构造函数调用" << endl;
    }
    ~Person()
    {
        cout << "Person的析构函数调用" << endl;
    }
};
// 析构函数
// 析构函数，没有返回值也不写void
// 函数名称与类名相同,在名称前加上符号 ~
// 析构函数不可以有参数，因此不可以发生重载
// 程序在对象销毁前会自动调用析构，无须手动调用,而且只会调用一次
void test1()
{
    Person p;//栈的数据，执行完后会释放
}
int main()
{
    //test1();
    Person p;
    system("pause");//->
    // 释放构造
    // 析构
    return 0;
}