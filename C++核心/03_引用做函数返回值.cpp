#include <iostream>
using namespace std;
// 引用做函数返回值
// 不要返回局部变量的引用
int &test1()
{
    int a = 10;
    return a;
}
// 函数的调用可以作为左值
int &test2()
{
    static int a = 10;
    return a;
}
// 引用的本质在C++内部的实现就是一个指针常量
void func(int &ref)
{
    ref = 100;
}
int main()
{
    int &ref = test1();
    // cout << ref << endl; // vs编译器进行了保留,vscode不保留
    // cout << ref << endl;
    int &ref2 = test2();
    cout << ref2 << endl;
    cout << ref2 << endl;
    test2() = 1000;
    cout << ref2 << endl;
    int a = 10;
    //自动转化为int *const ref = &a;
    int &ref = a;
    ref = 20; //*ref = 20;
    cout << a << endl;
    cout << ref << endl;
    func(a);
    return 0;
}