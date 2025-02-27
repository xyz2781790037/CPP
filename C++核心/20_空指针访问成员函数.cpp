#include <iostream>
using namespace std;
// C++中空指针也是可以调用成员函数的，但是也要注意有没有用到this指针

// 如果用到this指针，需要加以判断保证代码的健壮性
class Person
{
public:
    void ShowClassName()
    {
        cout << "我是Person类!" << endl;
    }

    void ShowPerson()
    {
        if (this == NULL)
        {
            return;
        }
        cout << this->mAge << endl;
    }

public:
    int mAge;
};
void test1()
{
    Person *p = NULL;
    p->ShowClassName(); // 空指针，可以调用成员函数
    p->ShowPerson();    // 但是如果成员函数中用到了this指针，就不可以了
}
int main()
{
    test1();
    return 0;
}