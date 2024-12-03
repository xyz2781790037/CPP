#include <iostream>
using namespace std;
// 函数重载条件
// 3.同一个作用域下
// 1.函数名称相同
// 2.函数参数类型不同 或者 个数不同 或者 顺序不同    返回值不可以作为函数重载的条件
void func()
{
    cout << "func调用" << endl;
}
void func(const int &a)
{
    cout << "func(const)调用" << endl;
}
void func(int a,double b)
{
    cout << "func(a调用" << endl;
}
void func(double a, int b)
{
    cout << "func(b调用" << endl;
}
//注意：引用作为重载条件
void func(int a)
{
    cout << "func调用" << endl;
}
void func(const int &a)
{
    cout << "func(const)调用" << endl;
}
//函数重载碰到默认参数
int func4(int a,int b = 10)
{
    cout << "fun4" << endl;
}
int func4(int a)
{
    cout << "ffd" << endl;
} // 出现二义性
int main()
{
    int a = 10;
    double b = 10;
    func();
    func(a,b);
    func(b, a);
    // func4(a);出现二义性
    return 0;
}