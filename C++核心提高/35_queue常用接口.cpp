#include <iostream>
#include <queue>
using namespace std;
// Queue是一种先进先出(First In First Out, FIFO) 的数据结构，它有两个出口
// 队列容器允许从一端新增元素，从另一端移除元素
// 队列中只有队头和队尾才可以被外界使用，因此队列不允许有遍历行为
// 队列中进数据称为 --- 入队 push
// 队列中出数据称为 --- 出队 pop

// 构造函数
// queue<T> que;            // queue采用模板类实现，queue对象的默认构造形式
// queue(const queue &que); // 拷贝构造函数

// 赋值操作
// queue &operator=(const queue &que); // 重载等号操作符

// 数据存取
// push(elem); // 往队尾添加元素
// pop();      // 从队头移除第一个元素
// back();     // 返回最后一个元素
// front();    // 返回第一个元素

// 大小操作
// empty(); // 判断堆栈是否为空
// size();  // 返回栈的大小
class Person
{
public:
    Person(string name, int age)
    {
        this->m_Name = name;
        this->m_Age = age;
    }
    string m_Name;
    int m_Age;
};
void test1()
{
    queue<Person> que;
    Person p1("唐僧", 30);
    Person p2("孙悟空", 1000);
    Person p3("猪八戒", 900);
    Person p4("沙僧", 800);
    que.push(p1);
    que.push(p2);
    que.push(p3);
    que.push(p4);

    cout << "first element name: " << que.front().m_Name << endl;
    cout << "first element age: " << que.front().m_Age << endl;
    cout << "last element name: " << que.back().m_Name << endl;
    cout << "last element age: " << que.back().m_Age << endl;

    cout << "queue size is: " << que.size() << endl;
    que.pop();
    cout << "size :" << que.size() << endl;
}
int main()
{
    test1();
    return 0;
}