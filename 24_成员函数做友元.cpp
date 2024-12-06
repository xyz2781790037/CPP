#include <iostream>
using namespace std;
class Building;
class goodGay
{
public:
    goodGay();
    void visit(); // 只让visit函数作为Building的好朋友，可以发访问Building中私有内容
    void visit2();

private:
    Building *building;
};
int main()
{
    return 0;
}