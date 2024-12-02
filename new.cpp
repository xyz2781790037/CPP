#include <iostream>
using namespace std;
int *func()
{
    // new返回该数据类型的指针
    int *p = new int(10);
    return p;
}
void test1()
{
    int *p = func();
    cout << *p << endl;
    // 释放堆区数据，delete
    delete p;
}
// 堆区开辟new数组
void test2()
{
    int *arr = new int[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = i + 10;
        cout << arr[i] << endl;
    }
    delete[] arr;
    cout << arr[1];
}
int main()
{
    test2();
    return 0;
}