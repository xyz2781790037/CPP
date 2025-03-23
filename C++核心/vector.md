# vector 
### vector构造函数
vector数据结构和数组非常相似，也称为单端数组
vector与普通数组区别：
- 不同之处在于数组是静态空间，而vector可以动态扩展
> 动态扩展：并不是在原空间之后续接新空间，而是找更大的内存空间，然后将原数据拷贝新空间，释放原空间
- vector容器的迭代器是支持随机访问的迭代器
```c++
#include <vector>
vector<T> v;  //采用模板实现类实现，默认构造函数
vector(v.begin(), v.end());    //将v[begin(), end())区间中的元素拷贝给本身。
vector(n, elem); //构造函数将n个elem拷贝给本身。
vector(const vector &vec); //拷贝构造函数。
```
```c++
#include <iostream>
#include <vector>
using namespace std;
void printVector(vector<int>& v){
    for (vector<int>::iterator it = v.begin(); it != v.end();it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
void test1()
{
    vector<int> v1; // 无参构造
    // vector<int> v1 = {1,2,3};
    for (int i = 0; i < 10;i++)
    {
        v1.push_back(i);
    }
    printVector(v1);
    vector<int> v2(v1.begin(), v1.end());
    printVector(v2);

    vector<int> v3(10, 100);
    printVector(v3);

    vector<int> v4(v3);
    printVector(v4);
}
```
```c++
0 1 2 3 4 5 6 7 8 9 
0 1 2 3 4 5 6 7 8 9 
100 100 100 100 100 100 100 100 100 100 
100 100 100 100 100 100 100 100 100 100 
```
### vector赋值操作
```c++
vector& operator=(const vector &vec);//重载等号操作符

assign(beg, end); //将[beg, end)区间中的数据拷贝赋值给本身。

assign(n, elem); //将n个elem拷贝赋值给本身。
```
```c++
void printVector(vector<int> &v)
{

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}
void test01()
{
    vector<int> v1; // 无参构造
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);

    vector<int> v2;
    v2 = v1;
    printVector(v2);

    vector<int> v3;
    v3.assign(v1.begin(), v1.end());
    printVector(v3);

    vector<int> v4;
    v4.assign(10, 100);
    printVector(v4);
}
```
```C++
0 1 2 3 4 5 6 7 8 9 
0 1 2 3 4 5 6 7 8 9 
0 1 2 3 4 5 6 7 8 9 
100 100 100 100 100 100 100 100 100 100
```
### vector容量和大小
```c++
empty();  //判断容器是否为空
capacity(); //容器的容量
size(); //返回容器中元素的个数
resize(int num); //重新指定容器的长度为num，若容器变长，则以默认值填充新位置。
​//如果容器变短，则末尾超出容器长度的元素被删除。
resize(int num, elem); //重新指定容器的长度为num，若容器变长，则以elem值填充新位置。
// 如果容器变短，则末尾超出容器长度的元素被删除
```c++
void test01()
{
    vector<int> v1;
    for (int i = 0; i < 10; i++)
    {
        v1.push_back(i);
    }
    printVector(v1);
    if (v1.empty())
    {
        cout << "v1为空" << endl;
    }
    else
    {
        cout << "v1不为空" << endl;
        cout << "v1的容量 = " << v1.capacity() << endl;
        cout << "v1的大小 = " << v1.size() << endl;
    }

    // resize 重新指定大小 ，若指定的更大，默认用0填充新位置，可以利用重载版本替换默认填充
    v1.resize(15, 10);
    printVector(v1);

    // resize 重新指定大小 ，若指定的更小，超出部分元素被删除
    v1.resize(5);
    printVector(v1);
}
```C++
0 1 2 3 4 5 6 7 8 9 
v1不为空
v1的容量 = 16
v1的大小 = 10
0 1 2 3 4 5 6 7 8 9 10 10 10 10 10 
0 1 2 3 4
```
### vector插入和删除
```C++
push_back(ele);                                  // 尾部插入元素ele
pop_back();                                      // 删除最后一个元素
insert(const_iterator pos, ele);                 // 迭代器指向位置pos插入元素ele
insert(const_iterator pos, int count, ele);      // 迭代器指向位置pos插入count个元素ele
erase(const_iterator pos);                       // 删除迭代器指向的元素
erase(const_iterator start, const_iterator end); // 删除迭代器从start到end之间的元素
clear();                                         // 删除容器中所有元素
```
```C++
void test1()
{
    vector<int> v1;
    // 尾插
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    v1.push_back(40);
    v1.push_back(50);
    printVector(v1);
    // 尾删
    v1.pop_back();
    printVector(v1);
    // 插入
    v1.insert(v1.begin(), 100);
    printVector(v1);

    v1.insert(v1.begin(), 2, 1000);
    printVector(v1);

    // 删除
    v1.erase(v1.begin());
    printVector(v1);

    // 清空
    v1.erase(v1.begin(), v1.end());
    v1.clear();
    printVector(v1);
}
```
```C++
10 20 30 40 50 
10 20 30 40 
100 10 20 30 40 
1000 1000 100 10 20 30 40 
1000 100 10 20 30 40
```
### 矢量数据访问
```C++
at(int idx); // 返回索引idx所指的数据
operator[];  // 返回索引idx所指的数据
front();     // 返回容器中第一个数据元素
back();      // 返回容器中最后一个数据元素
```
```c++
void test1()
{
    vector<int> v;
    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    cout << v.at(2) << " " << v[2] << endl;// 2 2
    cout << v.front() << " " << v.back(); // 0 9
}
```
### 矢量预留空间
```c++
reserve(int len); // 装设设备长个要素，装设设备不初始化，要素不可访问。
// 减少矢量在动态扩展时的扩展次数
```c++
void test01()
{
    vector<int> v;

    // 预留空间
    v.reserve(100000);

    int num = 0;
    int *p = nullptr;
    for (int i = 0; i < 100000; i++)
    {
        v.push_back(i);
        if (p != &v[0])
        {
            p = &v[0];
            num++;
        }
    }

    cout << "num:" << num << endl; // num:1
    cout << *p << endl;// 0
}
```