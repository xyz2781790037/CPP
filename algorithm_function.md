# algorithm头文件函数全集
algorithm头文件是C++的标准算法库，它主要应用在容器上。 以下是常用函数：
## 一、max()、min()、abs()函数
`max()`：求两个数最大值
`min()`：求两个数最小值
`abs()`：求一个数的绝对值
## 二、交换函数：swap()
`swap(a,b)`
## 三、翻转函数：reverse()
#### 翻转整个数组
```c++
#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int a[5] = {11,22,33,44,55};
	reverse(a,a+5);
	for(int i = 0; i < 5; i++) 
		cout << a[i] << ' ';
	return 0;
 } 
```
#### 实现对部分值的翻转
```c++
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	vector<int>v;
	//输入： 
	for(int i = 0; i < 5; i++) 
		v.push_back(i);
	//输出： 
	reverse(v.begin(), v.end());
	for(int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}
	return 0;
 } 
```
$\color{red}{**如果想在翻转时指定位数，则其为半开半闭区间。 如reserve(a+2, a+4);翻转数组中第2-4之间的数，不包括第二个，但包括第四个。**}
## 四、排序函数：sort()
1. 对x-y区间的数组、容器进行排序。**默认升序排列。**
```c++
#include<iostream>
#include<algorithm>
using namespace std;
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	vector<int>v;
	vector<int>::iterator it;
	//输入： 
	for(int i = 5; i > 0; i--) 
		v.push_back(i); 
	//输出： 
	it = v.begin(); 
	sort(it, it+3);
//	sort(v.begin(), v.end())
	for(int i = 0; i < v.size(); i++) {
		cout << v[i] << ' ';
	}
	return 0;
 } 

```
2. 如果想将数组降序排序，就需要写一个简单的函数，改变默认的排序功能
```c++
#include<iostream>
#include<algorithm>
//意思是：若a>b，则a的优先级更大！ 也就是说大的在前面。
bool cmp(int a, int b) {
	return a > b; 
}
using namespace std;
int main() {
	int a[5] = {55,44,33,22,11};
	
	sort(a,a+5,cmp);			//这里需要加上自己自定义的函数
	
	for(int i = 0; i < 5; i++) 
		cout << a[i] << ' ';
	return 0;
 } 
```
和reverse()函数一样，可以自由指定排序范围，也是**半开半闭区间（左闭右开）。**
## 五、查找函数：find()
==查找某数组指定区间x-y内是否有x，若有，则返回该位置的地址，若没有，则返回该数组第n+1个值的地址。==

**数组中查找是否有某值：一定要满足代码中这两个条件。**
> - 第一个条件是：p-a != 数组的长度。p是查找数值的地址，a是a[0]的地址。
>- 第二个条件是：*p == x; 也就是该地址指向的值等于我们要查找的值。
>- 最后输出p-a+1； p-a相当于x所在位置的地址-a[0]所在位置的地址， 但因为是从0开始算， 所以最后需要+1。
```C++
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
	vector<int>v;
	vector<int>::iterator it, it1;
	//输入： 
	for(int i = 0; i < 5; i++) 
		v.push_back(i); 
	//查找 
	int size = v.size();					//第一步：求长度
	it = find(v.begin(), v.end(), 3);		//第二步：查找x在容器的位置，返回迭代器1
	it1 = v.begin();						//第三步：令迭代器2指向容器头 
	if(((it-it1)!=size)&&(*it==3))			//第四步：若同时满足这两个条件，则查找成功，输出 
		cout << (it-it1+1) << endl;			//输出所在位置 
	return 0;
 } 
```
## 六、查找函数：upper_bound()、lower_bound()
1. `upper_bound()`：查找第一个大于x的值的位置
2. `lower_bound()`：查找第一个大于等于x的值的位置

同样是返回地址，用法和find()函数一样
## 七、填充函数：fill()
在区间内填充某一个值。
```c++
#include<iostream>
#include<algorithm>
using namespace std;
int main() {  
	int a[5] = {11,33,22};
	
	fill(a+3,a+5,9999);								
	
	for(int i = 0; i < 5; i++) 
		cout << a[i] << ' ';
	return 0;
 } 
```
## 八、查找某值出现的次数：count()
**在容器中查找同理，只是需要用iterator迭代器或begin()、end()函数。**
**注意是半开半闭区间(左闭右开区间)。**
```c++
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {  
	vector<int> v;
    for(int i = 0;i < 10;i++)
    {
        v.push_back(i);
    }
    cout << count(v.begin(),v.end(),6) << endl;
	return 0;
 } 
```
## 九、求最大公因数：__gcd()
**用二者乘积除以最大公因数即可得到最小公倍数。 因此没有求最小公倍数的函数。**
```c++
#include<iostream>
#include<algorithm>
using namespace std;
int main() {  
	int a = 12, b = 4;
	int Gcd = __gcd(a,b);
	cout << Gcd;
	return 0;
 } 

```
## 十、求交集、并集、差集：set_intersection()、set_union()、set_difference()
#### 求交集
1. 将两个数组的交集赋给一个容器(为什么不能赋给数组呢？因为数组不能动态开辟，且inserter()函数中的参数必须是指向容器的迭代器。)：
```c++
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
int main() {
	int a[5] = {1,2,3,4,5}, b[5] = {1,2,33,44,55};
	vector<int>::iterator it;
	vector<int>v4;	
	set_intersection(a, a+5, b, b+5, inserter(v4,v4.begin()));
	for(int i = 0; i < v4.size(); i++) {
		cout << v4[i] << ' ';
	}
```
2. 将两个容器的交集赋给另一个容器
```c++
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
int main() {
	vector<int> v1, v2, v3;
	for(int i = 0; i < 5; i++) 
		v1.push_back(i);
	for(int i = 3; i < 8; i++) 
		v2.push_back(i);
	  
	set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), inserter(v3,v3.begin()));  
	for(int i = 0; i < v3.size(); i++) {
		cout << v3[i] << ' ';
	}
	return 0;
} 
```
#### 求并集
将两个容器的并集赋给另一个容器
```c++
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
int main() {
	vector<int> v1, v2, v3;
	for(int i = 0; i < 5; i++) 
		v1.push_back(i);
	for(int i = 3; i < 8; i++) 
		v2.push_back(i);
	  
	set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), inserter(v3,v3.begin()));  
	for(int i = 0; i < v3.size(); i++) {
		cout << v3[i] << ' ';
	}
	return 0;
} 
```
#### 差集
**Same as before**
## 十一、全排列：next_permutation()
**将给定区间的数组、容器全排列**
```c++
#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;
int main() {
    vector<int> v;
    for(int i = 0;i < 4;i++)
    {
        v.push_back(i);
    }
    while(next_permutation(v.begin(),v.end()))
    {
        cout << v[0] << v[1] << v[2] << v[3] << endl;
    }
}
```
>[原文](https://blog.csdn.net/weixin_43899069/article/details/104450000?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522880737ec9cebb13e92d7e508eb282a12%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=880737ec9cebb13e92d7e508eb282a12&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-104450000-null-null.142^v101^pc_search_result_base1&utm_term=algorithm&spm=1018.2226.3001.4187)