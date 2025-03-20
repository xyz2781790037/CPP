#include <iostream>
#include <forward_list>
// push_front(value) 只能在头部插入
// 指定位置插入
// insert_after(it, value);
// 删除元素
// remove(value)；
// 删除指定位置
// erase_after(it)；
// 获取头部元素
// front()；
// before_begin()；
using namespace std;
int main(){
    forward_list<int> fl = {1, 2, 3, 4, 5};
    forward_list<int>::iterator it = fl.begin();
    fl.erase_after(it);
    it++;
    cout << *it << endl;
    for (int num : fl)
    {
        cout << num << " ";
    }
}