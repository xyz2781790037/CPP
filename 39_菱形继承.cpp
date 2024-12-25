#include <iostream>
using namespace std;
// 继承概念：
// ​两个派生类继承同一个基类
// ​ 另一个类同时继承者两个派生类
// ​ 这个继承被称为菱形继承，或者钻石继承

// 草泥马继承自动物的数据继承了两份，其实我们应该清楚，这份数据我们只需要一份就可以。
class Animal
{
public:
    int m_Age;
};
class Sheep : virtual public Animal
{
};
class Tuo : virtual public Animal
{
};
class SheepTuo : public Sheep, public Tuo
{
};
void test1()
{
    SheepTuo st;
    st.Sheep::m_Age = 100;
    st.Tuo::m_Age = 200;

    cout << "st.Sheep::m_Age = " << st.Sheep::m_Age << endl;
    cout << "st.Tuo::m_Age = " << st.Tuo::m_Age << endl;
    // 加了虚继承，结果才一样
    cout << "st.m_Age = " << st.m_Age << endl;
}
int main()
{
    test1();
    return 0;
}
// 菱形继承带来的主要问题是子类继承两份相同的数据，导致资源浪费以及毫无意义
// 利用虚继承可以解决菱形继承问题