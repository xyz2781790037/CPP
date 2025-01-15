#include <iostream>
// string substr(int pos = 0, int n = npos) const; // 返回由pos开始的n个字符组成的字符串
using namespace std;
// 子串
void test01()
{

    string str = "abcdefg";
    string subStr = str.substr(1, 3);
    cout << "subStr = " << subStr << endl;

    string email = "hello@sina.com";
    int pos = email.find("@");
    string username = email.substr(0, pos);
    cout << "username: " << username << endl;
}

int main()
{

    test01();
    return 0;
}
// 灵活的运用求子串功能，可以在实际开发中获取有效的信息