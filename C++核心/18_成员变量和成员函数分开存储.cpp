#include <iostream>
using namespace std;
// 在C++ 中，类内的成员变量和成员函数分开存储

// 只有非静态成员变量才属于类的对象上
class Person
{
    // 非静态成员变量占对象空间
    int mA;
    // 静态成员变量不占对象空间
    static int mB;
    // 函数也不占对象空间，所有函数共享一个函数实例
    void func()
    {
        cout << "mA:" << this->mA << endl;
    }
    // 静态成员函数也不占对象空间
    static void sfunc()
    {
    }
};
void test1()
{
    Person p;
    cout << "size = " << sizeof(p) << endl; // 1
    // C++编译器会给每个空对象分配1个字节，区分占内存的位置
    // 每个空对象应该有独一无二的内存地址
}
void test2()
{
    Person p;
    cout << "size = " << sizeof(p) << endl;
}
int main()
{
    test2();
    return 0;
}