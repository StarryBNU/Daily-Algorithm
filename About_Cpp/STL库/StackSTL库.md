在C++ STL（标准模板库）中，`std::stack` 是一个**容器适配器**，它基于底层容器（默认是 `std::deque`）提供了**后进先出（LIFO）**的数据结构。下面我们详细解析它。

---

## 1. 什么是容器适配器？
容器适配器不是独立的容器，而是对已有序列容器的接口进行封装，提供特定的行为模式。  
`stack` 只允许在容器的一端（称为栈顶）进行元素的插入、删除和访问，屏蔽了底层容器的其他操作。

---

## 2. `std::stack` 的模板定义
```cpp
template <class T, class Container = std::deque<T>>
class stack;
```
- `T`：存储的元素类型。
- `Container`：底层使用的容器类型，必须支持 `back()`、`push_back()`、`pop_back()`、`empty()`、`size()` 等操作。  
  默认使用 `std::deque`，也可以显式指定为 `std::vector`、`std::list` 等。

---

## 3. 为什么默认底层容器是 `deque`？
`std::deque`（双端队列）在尾部插入和删除元素的时间复杂度为 **O(1)**，且不会像 `vector` 那样在扩容时需要重新分配所有元素并移动数据。  
相比 `vector`：
- `deque` 的尾部操作同样高效；
- 当元素数量增长时，`deque` 不需要重新分配整个内存块，因此性能更稳定；
- 对于栈这种只在一端操作的结构，`deque` 比 `vector` 更合适。  

相比 `list`：
- `list` 是双向链表，虽然尾部操作也是 O(1)，但内存开销更大，且不连续存储会导致缓存不友好；
- `deque` 通常提供更好的内存局部性，实际运行效率更高。

因此，**`deque` 是兼顾效率与内存管理的默认选择**。

---

## 4. 核心成员函数
| 操作                      | 说明                                         |
| ------------------------- | -------------------------------------------- |
| `void push(const T& val)` | 将元素压入栈顶（调用底层容器的 `push_back`） |
| `void pop()`              | 弹出栈顶元素（调用底层容器的 `pop_back`）    |
| `T& top()`                | 返回栈顶元素的引用（调用底层容器的 `back`）  |
| `bool empty()` const      | 判断栈是否为空                               |
| `size_type size()` const  | 返回栈中元素个数                             |

**注意**：`pop()` 仅移除元素，不返回被移除的元素；`top()` 仅返回元素，不移除。这与某些其他语言的设计不同。

---

## 5. 代码示例
```cpp
#include <iostream>
#include <stack>

int main() {
    std::stack<int> s;  // 默认使用 deque

    // 压栈
    s.push(10);
    s.push(20);
    s.push(30);

    // 访问栈顶
    std::cout << "栈顶元素: " << s.top() << std::endl;  // 输出 30

    // 弹出栈顶
    s.pop();
    std::cout << "弹出后栈顶: " << s.top() << std::endl; // 输出 20

    // 遍历并弹出所有元素
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << std::endl; // 输出 20 10

    return 0;
}
```

---

## 6. 使用其他底层容器
可以显式指定底层容器，例如使用 `std::vector`：
```cpp
std::stack<int, std::vector<int>> s_vec;
s_vec.push(1);
s_vec.push(2);
```
只要该容器提供了 `back()`、`push_back()`、`pop_back()` 等方法即可。

---

## 7. 总结
- `std::stack` 是基于现有容器的**适配器**，默认使用 `std::deque`。
- 它强制了 LIFO 的访问方式，简化了栈的使用场景。
- 选择 `deque` 作为默认底层是因为它在尾部操作的高效性和稳定的内存管理。
- 若需要自定义底层容器，只需满足接口要求即可。