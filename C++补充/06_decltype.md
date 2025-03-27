# decltype用法详解
### 什么是decltype
decltype是C++11新增的一个关键字，和auto的功能一样，用来在编译时期进行自动类型推导。引入decltype是因为auto并不适用于所有的自动类型推导场景，在某些特殊情况下auto用起来很不方便，甚至压根无法使用。
```c++
auto varName=value;
decltype(exp) varName=value;
```
- auto根据=右边的初始值推导出变量的类型，decltype根据exp表达式推导出变量的类型，跟=右边的value没有关系
- auto要求变量必须初始化，这是因为auto根据变量的初始值来推导变量类型的，如果不初始化，变量的类型也就无法推导
- 原则上将，exp只是一个普通的表达式，它可以是任意复杂的形式，但必须保证exp的结果是有类型的，不能是void；如exp为一个返回值为void的函数时，exp的结果也是void类型，此时会导致编译错误
```c++
decltype(exp) varName;
```
### 推导规则
- 如果exp是一个不被括号()包围的表达式，或者是一个类成员访问表达式，或者是一个单独的变量，decltype(exp)的类型和exp一致
- 如果exp是函数调用，则decltype(exp)的类型就和函数返回值的类型一致
- 如果exp是一个左值，或被括号()包围，decltype(exp)的类型就是exp的引用，假设exp的类型为T，则decltype(exp)的类型为T&
[原文](https://blog.csdn.net/qq_38196982/article/details/118578967)