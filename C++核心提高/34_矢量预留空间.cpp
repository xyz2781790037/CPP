#include <iostream>
#include <vector>
using namespace std;
// reserve(int len); // 装设设备长个要素，装设设备不初始化，要素不可访问。
// 减少矢量在动态扩展时的扩展次数
void test01()
{
    vector<int> v;

    // 预留空间
    v.reserve(100000);

    int num = 0;
    int *p = NULL;
    for (int i = 0; i < 100000; i++)
    {
        v.push_back(i);
        if (p != &v[0])
        {
            p = &v[0];
            num++;
        }
    }

    cout << "num:" << num << endl;
}
int main()
{
    test01();
    return 0;
}
// 如果数据量增大，可以开始利用储备研发空间