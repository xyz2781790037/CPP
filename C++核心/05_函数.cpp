#include <iostream>
using namespace std;
int func(int a, int b = 0, int c = 10)
{
    return a + b + c;
}
// 如果函数的声明有默认参数，那么函数的实现就不能有默认参数 => 声明和实现只能有一个有默认参数
int func2(int a = 10, int b = 10);
int func2(int a, int b)
{
    return a + b;
}
// 如果一个位置已经有了默认值，那么从这个位置往后，从左向右都必须有默认值
// int func2(int a = 10, int b, int c);
int func3(int a, int b, char = 10)//占位用
{
    return a + b + 10;
}
int main()
{
    // 形参有默认值
    cout << func(10, 20) << endl;
    return 0;
}