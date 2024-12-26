#include <iostream>
using namespace std;
//值传递
void swap(int a,int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
//地址传递
void swap1(int *a,int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
//引用传递
void swap2(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
int main()
{
    // 引用基本：数据类型 &别名 = 原名
    int a = 10;
    int &b = a; // int &b;-> error!
    //一旦初始化，不可以改变
    int c = 20;
    //int &b = c; ->error!
    cout << a << endl;
    b = 100;
    cout << b << endl;
    cout << a << endl;
    int d = 10;
    swap1(&a, &b);
    swap2(a,b);
    return 0;
}