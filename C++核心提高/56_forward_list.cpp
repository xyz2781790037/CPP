#include <iostream>
#include <forward_list>
#include <algorithm>
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
// std::forward_list<int> fl2(fl1);

using namespace std;
int main(){
    forward_list<int> fl = {1, 2, 3, 4, 5};
    forward_list<int>::iterator it = fl.begin();
    fl.erase_after(it);
    it++;
    cout << *it << endl;
    // std::forward_list<int> fl1 = {1, 2, 3, 4, 5};
    // std::forward_list<int> fl2;

    // fl2 = fl1; // 赋值操作
    for (int num : fl)
    {
        cout << num << " ";
    }
    // std::forward_list<int> fl;

    // // 用列表赋值
    // fl.assign({1, 2, 3, 4, 5});

    // std::cout << "fl: ";
    // for (int num : fl)
    // {
    //     std::cout << num << " ";
    // }
    // std::cout << std::endl;

    // // 用多个相同的值赋值
    // fl.assign(3, 100); // 赋值 3 个 100

    // std::cout << "fl after assign(3, 100): ";
    // for (int num : fl)
    // {
    //     std::cout << num << " ";
    // }
    // return 0;
}