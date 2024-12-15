#include <iostream>
using namespace std;
class mydecrease
{
    friend ostream &operator<<(ostream &out, mydecrease p);

public:
    mydecrease()
    {
        m_a = 0;
    }
    mydecrease &operator--()
    {
        m_a--;
        return *this;
    }
    mydecrease &operator--(int)
    {
        mydecrease* tmp = new mydecrease;
        *tmp = *this;
        m_a--;
        return *tmp;
    }

private:
    int m_a;
};
ostream &operator<<(ostream &out, mydecrease p)
{
    out << p.m_a;
    return out;
}
void test1()
{
    mydecrease p;
    cout << --(--p) << endl;
    cout << p << endl;
}
void test2()
{
    mydecrease pp;
    cout << pp-- << endl;
    cout << pp << endl;
}
int main()
{
    test2();
    // test1();
    return 0;
}