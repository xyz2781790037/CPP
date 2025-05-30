#include <iostream>
using namespace std;
// 普通实现
class calculator
{
public:
    int result(string oper)
    {
        if (oper == "+")
        {
            return m_num1 + m_num2;
        }
        else if (oper == "-")
        {
            return m_num1 - m_num2;
        }
        else if (oper == "*")
        {
            return m_num1 * m_num2;
        }
        else if(oper == "/")
        {
            return m_num1 / m_num2;
        }
        return 0;
    }
public:
    int m_num1;
    int m_num2;
};
void test1()
{
    calculator c;
    c.m_num1 = 10;
    c.m_num2 = 10;
    cout << c.m_num1 << " + " << c.m_num2 << " = " << c.result("+") << endl;
    cout << c.m_num1 << " - " << c.m_num2 << " = " << c.result("-") << endl;
    cout << c.m_num1 << " * " << c.m_num2 << " = " << c.result("*") << endl;
    cout << c.m_num1 << " / " << c.m_num2 << " = " << c.result("/") << endl;
}
// 多态实现
// 抽象计算器类
// 多态优点：代码组织结构清晰，可读性强，利于前期和后期的扩展以及维护
class AbstractCalculator
{
    public:
    virtual int getResult()
    {
        return 0;
    }
    int m_Num1;
    int m_Num2;
};
// 加法计算器
class AddCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return m_Num1 + m_Num2;
    }
};

// 减法计算器
class SubCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return m_Num1 - m_Num2;
    }
};

// 乘法计算器
class MulCalculator : public AbstractCalculator
{
public:
    int getResult()
    {
        return m_Num1 * m_Num2;
    }
};
void test2()
{
    // 创建加法计算器
    AbstractCalculator *abc = new AddCalculator;
    abc->m_Num1 = 10;
    abc->m_Num2 = 10;
    cout << abc->m_Num1 << " + " << abc->m_Num2 << " = " << abc->getResult() << endl;
    delete abc; // 用完了记得销毁

    //创建减法计算器
	abc = new SubCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << " - " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;  

	//创建乘法计算器
	abc = new MulCalculator;
	abc->m_Num1 = 10;
	abc->m_Num2 = 10;
	cout << abc->m_Num1 << " * " << abc->m_Num2 << " = " << abc->getResult() << endl;
	delete abc;
}
int main()
{
    test1();
    return 0;
}
// 总结：C++开发利用多态设计程序架构，因为多态优点很多