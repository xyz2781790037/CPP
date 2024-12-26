#include <iostream>
#include <string>
using namespace std;
class stud
{
public:
    void setname(string myname)
    {
        name = myname;
    }
    string getname()
    {
        return name;
    }
    int getage()
    {
        return age;
    }
    void setidol(string myidol)
    {
        idol = myidol;
    }
void setage(int myage)
{
    if(age < 0 || age > 150)
    {
        cout << "error age" << endl;
        return;
    }
    age = myage;
}
private:
    string name;  // RW
    int age = 18; // R
    string idol;  // W
};
int main()
{
    stud s1;
    s1.setname("zyx");
    cout << s1.getname() << endl;

    cout << s1.getage() << endl;
    s1.setidol("张帆");
    return 0;
}