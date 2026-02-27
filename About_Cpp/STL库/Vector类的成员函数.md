在 **C++98 标准**下，`std::vector<T>` 是 STL 中最常用的动态数组容器。它提供了一系列成员函数用于访问、修改、查询和管理其内部元素。

下面列出 **C++98 中 `vector` 的主要成员函数**（按功能分类），并附上简要说明和典型用法（**全部符合 C++98 语法**）。

---

## 一、构造与析构（Constructors / Destructor）

| 函数                                        | 说明                                                         |
| ------------------------------------------- | ------------------------------------------------------------ |
| `vector()`                                  | 默认构造：创建空 vector                                      |
| `vector(size_type n, const T& value = T())` | 创建包含 `n` 个 `value` 的 vector（若未提供 `value`，则用默认构造或 0 初始化） |
| `vector(const vector& x)`                   | 拷贝构造                                                     |
| `~vector()`                                 | 析构函数（自动调用）                                         |

✅ 示例（C++98）：
```cpp
vector<int> a;                    // 空
vector<int> b(5, 10);             // {10,10,10,10,10}
vector<int> c(b);                 // 拷贝 b
```

> ⚠️ C++98 **不支持**初始化列表（如 `vector<int> v = {1,2,3};`），也不支持 `initializer_list`。

---

## 二、赋值操作（Assignment）

| 函数                         | 说明                 |
| ---------------------------- | -------------------- |
| `operator=(const vector& x)` | 赋值操作符（深拷贝） |

```cpp
a = b; // 将 b 的内容复制给 a
```

---

## 三、迭代器（Iterators）

| 函数       | 返回类型           | 说明                             |
| ---------- | ------------------ | -------------------------------- |
| `begin()`  | `iterator`         | 指向第一个元素                   |
| `end()`    | `iterator`         | 指向最后一个元素**之后**的位置   |
| `rbegin()` | `reverse_iterator` | 反向迭代器（指向最后一个元素）   |
| `rend()`   | `reverse_iterator` | 反向迭代器（指向第一个元素之前） |

✅ 遍历示例（C++98）：
```cpp
for (vector<int>::iterator it = a.begin(); it != a.end(); ++it) {
    cout << *it << " ";
}
```

---

## 四、容量相关（Capacity）

| 函数                               | 返回类型    | 说明                                           |
| ---------------------------------- | ----------- | ---------------------------------------------- |
| `size()`                           | `size_type` | 当前元素个数                                   |
| `max_size()`                       | `size_type` | 系统允许的最大元素数（通常很大）               |
| `capacity()`                       | `size_type` | 当前分配的存储空间能容纳的元素数（≥ size）     |
| `empty()`                          | `bool`      | 是否为空（等价于 `size() == 0`）               |
| `reserve(size_type n)`             | `void`      | 预分配至少 `n` 个元素的空间（不改变 `size()`） |
| `resize(size_type n, T val = T())` | `void`      | 改变 `size()` 到 `n`，新增元素用 `val` 填充    |

✅ 注意：
- `resize()` 会**改变实际元素数量**；
- `reserve()` **只预分配内存，不影响逻辑大小**。

---

## 五、元素访问（Element Access）

| 函数                      | 说明                                                         |
| ------------------------- | ------------------------------------------------------------ |
| `operator[](size_type n)` | 返回第 `n` 个元素（**不检查边界！**）                        |
| `at(size_type n)`         | 返回第 `n` 个元素（**带边界检查，越界抛出 `out_of_range`**） |
| `front()`                 | 返回第一个元素的引用                                         |
| `back()`                  | 返回最后一个元素的引用                                       |

✅ 示例：
```cpp
if (!a.empty()) {
    int first = a.front();
    int last  = a.back();
    a[0] = 100;      // 快速访问
    a.at(0) = 100;   // 安全访问（但慢一点）
}
```

> 📌 算法竞赛中通常用 `[]`（因性能高且数据合法）。

---

## 六、修改器（Modifiers）

| 函数                                            | 说明                                                    |
| ----------------------------------------------- | ------------------------------------------------------- |
| `assign(size_type n, const T& val)`             | 用 `n` 个 `val` 赋值给当前 vector（等价于先清空再填充） |
| `push_back(const T& x)`                         | 在末尾添加一个元素                                      |
| `pop_back()`                                    | 删除最后一个元素（**不返回值！**）                      |
| `insert(iterator pos, const T& x)`              | 在 `pos` 前插入 `x`，返回插入位置的迭代器               |
| `insert(iterator pos, size_type n, const T& x)` | 在 `pos` 前插入 `n` 个 `x`                              |
| `erase(iterator pos)`                           | 删除 `pos` 处的元素                                     |
| `erase(iterator first, iterator last)`          | 删除 `[first, last)` 区间内的元素                       |
| `clear()`                                       | 清空所有元素（`size()` 变为 0，但 `capacity()` 不变）   |
| `swap(vector& x)`                               | 与另一个 vector 交换内容（常数时间）                    |

✅ 常用组合：
```cpp
a.push_back(5);     // 添加
a.pop_back();       // 删除最后一个
a.clear();          // 清空
```

> ⚠️ `pop_back()` **不返回值**！如果要取值再删除，应：
```cpp
int x = a.back();
a.pop_back();
```

---

## 七、其他

| 函数              | 说明                             |
| ----------------- | -------------------------------- |
| `get_allocator()` | 返回内存分配器（竞赛中几乎不用） |

---

## 八、注意事项（C++98 特有）

1. **嵌套模板必须加空格**：
   ```cpp
   vector<vector<int> > v; // ✅
   vector<vector<int>> v;  // ❌ C++98 编译错误
   ```

2. **不支持 C++11 以后的特性**：
   - 无 `emplace_back`
   - 无 `shrink_to_fit`
   - 无 初始化列表 `{1,2,3}`
   - 无 `cbegin()` / `cend()`（const 迭代器）

3. **性能提示**：
   - `push_back` 均摊 O(1)，但可能触发内存重分配；
   - 若知道大致大小，先 `reserve(n)` 可避免多次拷贝。

---

## 九、算法竞赛常用模式（C++98）

```cpp
// 1. 声明
vector<int> path;

// 2. 添加/删除（回溯经典）
path.push_back(x);
dfs(...);
path.pop_back(); // 注意：不返回值！

// 3. 遍历
for (int i = 0; i < path.size(); ++i) {
    cout << path[i] << " ";
}

// 或用迭代器（稍慢）
for (vector<int>::iterator it = path.begin(); it != path.end(); ++it) {
    cout << *it << " ";
}

// 4. 清空
path.clear();
```

---

✅ 总结：  
在 C++98 算法竞赛中，`vector` 最常用的就是：
- `push_back`, `pop_back`
- `size()`, `empty()`
- `clear()`
- `operator[]`
- 构造时指定大小：`vector<int> v(n, 0);`

掌握这些，足以应对 99% 的题目（包括 P1219）。