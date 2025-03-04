### **`function` 容器：存储和调用可调用对象**

`function` 是 C++ 标准库中的一个**通用函数包装器**，它可以存储**任意可调用对象**（包括普通函数、lambda、函数指针、仿函数等）。它主要用于：

- 作为回调函数
- 存储不同类型的可调用对象
- 适用于 `std::bind` 绑定参数
- 作为高阶函数参数传递

### `function` 基本用法

#### （1）存储普通函数

```c++
#include <iostream>
#include <functional>
using namespace std;

void hello() {
    cout << "Hello, World!" << endl;
}

int main() {
    std::function<void()> func = hello;  // 存储普通函数
    func();  // 调用，输出：Hello, World!
    return 0;
}
```

#### （2）存储 lambda 表达式

```c++
#include <iostream>
#include <functional>
using namespace std;

int main() {
    std::function<int(int, int)> add = [](int a, int b) { return a + b; };

    cout << add(3, 5) << endl;  // 输出：8
    return 0;
}
```

#### （3）存储成员函数

```c++
#include <iostream>
#include <functional>
using namespace std;

class Test {
public:
    void show(int x) {
        cout << "Value: " << x << endl;
    }
};

int main() {
    Test obj;
    std::function<void(Test&, int)> func = &Test::show;

    func(obj, 42);  // 调用成员函数，输出：Value: 42
    return 0;
}
```

#### 4）存储仿函数（重载 `operator()` 的类）

```c++
#include <iostream>
#include <functional>
using namespace std;

struct Multiply {
    int operator()(int a, int b) { return a * b; }
};

int main() {
    std::function<int(int, int)> func = Multiply();
    
    cout << func(4, 6) << endl;  // 输出 24
    return 0;
}
```

仿函数是一种特殊的可调用对象，`function` 也能存储它。

### 2. `std::function` 高级用法

#### （1）用于回调机制

```c++
#include <iostream>
#include <functional>
using namespace std;

void runCallback(std::function<void(int)> callback, int value) {
    callback(value);
}

void printValue(int x) {
    cout << "Value: " << x << endl;
}

int main() {
    runCallback(printValue, 10);  // 输出：Value: 10

    // 也可以传 lambda
    runCallback([](int x) { cout << "Lambda: " << x << endl; }, 20);  
}
```

> [回调函数(callback)是什么](https://blog.csdn.net/Long_xu/article/details/131320301?ops_request_misc=%257B%2522request%255Fid%2522%253A%252265c9fd45cc369f3713a64dffb0e9ce4a%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=65c9fd45cc369f3713a64dffb0e9ce4a&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-131320301-null-null.142^v101^pc_search_result_base1&utm_term=callback%E5%9B%9E%E8%B0%83%E5%87%BD%E6%95%B0&spm=1018.2226.3001.4187)

#### （2）`std::bind` 绑定参数

`std::bind` 允许预先绑定函数的部分参数，返回一个新的可调用对象。

```c++
#include <iostream>
#include <functional>
using namespace std;

int add(int a, int b) {
    return a + b;
}

int main() {
    std::function<int(int)> add5 = std::bind(add, 5, std::placeholders::_1);

    cout << add5(3) << endl;  // 输出 8
}

```

#### （3）存储不同类型的可调用对象

```c++
#include <iostream>
#include <functional>
using namespace std;

int func1(int a, int b) { return a + b; }
struct Func2 { int operator()(int a, int b) { return a * b; } };

int main() {
    std::function<int(int, int)> f;

    f = func1;   // 存储普通函数
    cout << f(3, 4) << endl;  // 输出 7

    f = Func2(); // 存储仿函数
    cout << f(3, 4) << endl;  // 输出 12

    f = [](int a, int b) { return a - b; };  // 存储 lambda
    cout << f(3, 4) << endl;  // 输出 -1
}

```

## **3. `std::function` vs 函数指针**

| **对比项**                    | **`std::function`** | **函数指针 (`int (\*)(int, int)`)** |
| ----------------------------- | ------------------- | ----------------------------------- |
| **支持 lambda**               | ✅ 是                | ❌ 否                                |
| **支持成员函数**              | ✅ 是                | ❌ 需 `std::bind`                    |
| **支持仿函数**                | ✅ 是                | ❌ 否                                |
| **支持 `std::bind` 绑定参数** | ✅ 是                | ❌ 否                                |
| **可变性（存储不同函数）**    | ✅ 是                | ❌ 否                                |