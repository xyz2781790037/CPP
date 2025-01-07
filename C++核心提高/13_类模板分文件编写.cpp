//#include "13_类模板分文件编写.cpp" //解决方式1，包含cpp源文件
// 解决方式2，将声明和实现写到一起，文件后缀名改为.hpp
#include "13_类模板分文件编写.hpp"
void test01()
{
    Person<string, int> p("Tom", 10);
    p.showPerson();
}
int main()
{
    test01();
    return 0;
}
// 总结：主流的解决方式是第二种，将类模板成员函数写到一起，并将后缀名改为.hpp