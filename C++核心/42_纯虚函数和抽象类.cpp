#include <iostream>
using namespace std;
// 在多态中，通常父类中虚函数的实现是没有意义的，主要是调用子类重写的内容
// 因此可以将虚函数改为纯虚函数
// 虚函数语法：virtual 返回值类型 函数名 （参数列表）= 0 ;
// 当类中有纯虚函数时，这个类也称为"抽象类 "
// 抽象类特点：
// 无法实例化对象
// 子类必须重写抽象类中的纯虚函数，否则也属于抽象类
class Base
{
public:
    // 纯虚函数
    // 类中只要有一个纯虚函数就称为抽象类
    // 抽象类无法实例化对象
    // 子类必须重写父类中的纯虚函数，否则也属于抽象类
    virtual void func() = 0;
};

class Son : public Base
{
public:
    virtual void func()
    {
        cout << "func调用" << endl;
    };
};

void test01()
{
    Base *base = NULL;
    // Base b // error
    //  base = new Base; // 错误，抽象类无法实例化对象
    base = new Son;
    base->func();
    delete base; // 记得销毁
    Son s;
    s.func();
}
int main()
{
    test01();
    return 0;
}