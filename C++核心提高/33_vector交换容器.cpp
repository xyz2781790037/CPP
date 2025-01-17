#include <iostream>
#include <vector>
using namespace std;
// swap(vec); // 将vec与本身的元素互换
void printVector(vector<int>& v)
{
    // for (vector<int>::iterator v1 = v.begin(); v1 != v.end();v1++)
    // {
    //     cout << *v1 << " ";
    // }
    for (int i = 0; i < v.size();i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
void test1()
{
    vector<int> v1;
    for (int i = 0; i < 10;i++)
    {
        v1.push_back(i);
    }
    printVector(v1);
    vector<int> v2;
    for (int i = 10; i > 0; i--)
    {
        v2.push_back(i);
    }
    printVector(v2);
    // 互换容器
    cout << "互换后" << endl;
    v1.swap(v2);
    printVector(v1);
    printVector(v2);
}
void test02()
{
    vector<int> v;
    for (int i = 0; i < 100000; i++)
    {
        v.push_back(i);
    }

    cout << "v的容量为：" << v.capacity() << endl;
    cout << "v的大小为：" << v.size() << endl;

    v.resize(3);

    cout << "v的容量为：" << v.capacity() << endl;
    cout << "v的大小为：" << v.size() << endl;

    // 收缩内存
    vector<int>(v).swap(v); // 匿名对象
    // vector<int>(v)：这部分代码创建了一个新的 vector<int> 对象，初始化为与 v 相同的内容。即，它是 v 的副本。

    // .swap(v)：这部分代码将新创建的 vector<int> 对象和原有的 v 对象交换内容。交换后，v 会拥有新的内存分配，而原来的 v 对象被销毁。
    cout << "v的容量为：" << v.capacity() << endl;
    cout << "v的大小为：" << v.size() << endl;
}

int main()
{
    //test1();
    test02();
    return 0;
}
// swap可以使两个容器互换，可以达到实用的压缩内存效果
