#include <iostream>
using namespace std;
// 可以用const修饰防止形参修改实参
void showValue(const int &ref)
{
    //ref = 1000;
    cout << ref << endl;
}
int main()
{
    // 引用常量：修饰形参，防止误操作
    // int a = 10;
    // 加上const -> int temp = 10; const int &ref = temp;
    const int &ref = 10;
    int a = 100;
    showValue(a);
    cout << a << endl;
    
    return 0;
}