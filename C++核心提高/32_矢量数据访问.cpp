#include <iostream>
#include <vector>
using namespace std;
// at(int idx); // 返回索引idx所指的数据
// operator[];  // 返回索引idx所指的数据
// front();     // 返回容器中第一个数据元素
// back();      // 返回容器中最后一个数据元素
void test1()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    cout << v.at(2) << " " << v[2] << endl;
    cout << v.front() << " " << v.back();
}
int main()
{
    test1();
    return 0;
}