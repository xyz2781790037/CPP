#include <iostream>
// 函数调用运算符 () 也可以重载
// 由于重载后使用的方式非常像函数的调用，因此称为仿函数
// 仿函数没有固定写法，非常灵活
using namespace std;
class myprint
{
public:
    void operator()(string text)
    {
        cout << text << endl;
    }
};
class MyAdd
{
public:
    int operator()(int v1, int v2)
    {
        return v1 + v2;
    }
};
void myprint2(string str)
{
    cout << str << endl;
}
void test1()
{
    myprint myprint1; // 重载的（）操作符 也称为仿函数
    myprint1("hello world");
    myprint2("hello world");
}
void test2()
{
    MyAdd add;
    int ret = add(10, 10);
    cout << "ret = " << ret << endl;

    // 匿名对象调用
    cout << "MyAdd()(100,100) = " << MyAdd()(100, 100) << endl;
}
int main()
{
    test1();
    test2();
    return 0;
}