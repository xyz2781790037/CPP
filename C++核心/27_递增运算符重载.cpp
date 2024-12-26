#include <iostream>
using namespace std;
class MyInteger
{

    friend ostream &operator<<(ostream &out, MyInteger myint);

public:
    MyInteger()
    {
        m_Num = 0;
    }
    // 前置++
    MyInteger &operator++()
    {
        // 先++
        m_Num++;
        // 再返回
        return *this; //*this 是返回自己
    }

    // 后置++
    MyInteger operator++(int)
    {
        // 先返回
        MyInteger temp = *this; // 记录当前本身的值，然后让本身的值加1，但是返回的是以前的值，达到先返回后++；
        m_Num++;
        return temp;
    }
    // MyInteger &operator++(int) // 占位参数
    // {
    //     // 先返回
    //     MyInteger *temp = new MyInteger; // 记录当前本身的值，然后让本身的值加1，但是返回的是以前的值，达到先返回后++；
    //     *temp = *this;
    //     m_Num++;
    //     return *temp;
    // }

private:
    int m_Num;
};
ostream &operator<<(ostream &out, MyInteger myint)
{
    cout << myint.m_Num;
    return out;
}
// 前置++ 先++ 再返回
void test01()
{
    MyInteger myint;
    cout << ++(++myint) << endl;
    cout << myint << endl;
}
void test2()
{
    MyInteger myInt;
    cout << myInt++ << endl;
    cout << myInt << endl;
}
int main()
{
    test2();
    return 0;
}