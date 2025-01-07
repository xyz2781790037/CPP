#include <iostream>
using namespace std;
template <class T>
void myswap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}
template <class T>
void sortt(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (arr[i] < arr[j])
            {
                myswap(arr[i], arr[j]);
            }
        }
    }
}
template <typename T>
void printarr(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void test1()
{
    char charArr[] = "bdcfeagh";
    int num = sizeof(charArr) / sizeof(char);
    sortt(charArr, num);
    printarr(charArr, num);
}
void test2()
{
    int intArr[] = {7, 5, 8, 1, 3, 9, 2, 4, 6};
    int num = sizeof(intArr) / sizeof(int);
    sortt(intArr, num);
    printarr(intArr, num);
}
int main()
{
    test1();
    test2();
    return 0;
}