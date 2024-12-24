#include <iostream>
using namespace std;
class Base
{
public:
    int m_A;

protected:
    int m_B;

private:
    int m_C; // 私有成员只是被隐藏了，但是还是会继承下去
};

// 公共继承
class Son : public Base
{
public:
    int m_D;
};

void test01()
{
    cout << "sizeof Son = " << sizeof(Son) << endl;//16
}
//结论： 父类中私有成员也是被子类继承下去了，只是由编译器给隐藏后访问不到 
int main()
{

    test01();
    return 0;
}