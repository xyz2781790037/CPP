// 注意事项：
// 自动类型推导，必须推导出一致的数据类型T,才可以使用
// 模板必须要确定出T的数据类型，才可以使用
#include <iostream>
using namespace std;
// 利用模板提供通用的交换函数
template<class T>
void mySwap(T& a,T& b)
{
    T temp = a;
    a = b;
    b = temp;
}
// 1、自动类型推导，必须推导出一致的数据类型T,才可以使用
void test1()
{
    int a = 10;
    int b = 20;
    char c = 'c';
    mySwap(a, b);
    // mySwap(a, c); // 错误，推导不出一致的T类型
}
// 2、模板必须要确定出T的数据类型，才可以使用
template <class T>
void func()
{
    cout << "func using" << endl;
}
void test2()
{
    // func(); //错误，模板不能独立使用，必须确定出T的类型
    func<int>(); // 利用显示指定类型的方式，给T一个类型，才可以使用该模板
}
int main()
{
    test1();
    test2();
    return 0;
}