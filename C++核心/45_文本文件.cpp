// 程序运行时产生的数据都属于临时数据，程序一旦运行结束都会被释放
// 通过文件可以将数据持久化
// C++ 中对文件操作需要包含头文件<fstream>
#include <fstream>
using namespace std;
// 文件类型分为两种：
// 文本文件 - 文件以文本的ASCII码形式存储在计算机中
// 二进制文件 - 文件以文本的二进制形式存储在计算机中，用户一般不能直接读取它们
// 操作员类别 :
// ofstream：写操作 ifstream：读操作 fstream ： 读写操作
// 写文件步骤如下：
// 包含文件
// #包括 <fstream>
// 创建流对象
// ofstream ofs；
// 打开文件
// ofs.open("文件路径",打开方式);
// 写数据
// ofs << "写入数据";
// 关闭文件
// ofs.close()；
// ios::in	    为读文件而打开文件
// ios::out	    为写文件而打开文件
// ios::ate	    初始位置：文件尾
// ios::app	    追加方式写文件
// ios::trunc 	如果文件存在先删除，再创建
// ios::binary	二进制方式
// 文件打开方式可以配合使用，利用|操作符
void test1()
{
    ofstream ofs;
    ofs.open("45_test.txt", ios::out);

    ofs << "姓名：张三" << endl;
    ofs << "性别：男" << endl;
    ofs << "年龄：18" << endl;

    ofs.close();
}

int main()
{
    test1();
    return 0;
}
// 文件操作必须包含头文件 fstream
// 读取文件可以利用 ofstream ，或者fstream类
// 打开文件的时候需要指定操作文件的路径，以及打开方式
// 利用<<可以向文件中写数据
// 操作完毕，要关闭文件