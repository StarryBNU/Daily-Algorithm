回溯（Backtracking）、深度优先搜索（DFS）和广度优先搜索（BFS）是算法竞赛中三大基础搜索策略。它们既有联系，也有明显区别。下面从**思想、实现、关系、应用场景**等方面系统对比，并结合 **C++98 标准下的典型代码模板**说明。

---

## 一、核心思想对比

| 算法     | 搜索方式               | 数据结构        | 是否记录路径           | 典型用途                      |
| -------- | ---------------------- | --------------- | ---------------------- | ----------------------------- |
| **DFS**  | 沿一条路走到黑，再回退 | 递归栈 / 显式栈 | 可选                   | 图遍历、连通性、拓扑排序      |
| **BFS**  | 一层一层往外扩         | 队列            | 可选                   | 最短路径（无权图）、层级遍历  |
| **回溯** | 构造解 + 试探 + 撤销   | 递归栈（隐式）  | **必须记录当前解状态** | 组合问题（N皇后、数独、子集） |

> ✅ **关键洞察**：  
> **回溯 = 带“撤销操作”的 DFS**，专门用于**构造完整解**的问题。

---

## 二、三者关系

- **DFS 是回溯的基础**：回溯用 DFS 的“深入+回退”机制；
- **但 DFS 不一定是回溯**：比如单纯遍历图不需要“撤销”；
- **BFS 一般不用于回溯**：因为 BFS 是横向扩展，难以维护单一解路径。

> 📌 回溯问题几乎总是用 **DFS 实现**，但加了“状态恢复”。

---

## 三、C++98 代码模板（严格兼容）

### 1. 深度优先搜索（DFS）——图遍历
```cpp
#include <iostream>
using namespace std;

const int MAXN = 100;
bool visited[MAXN];
int graph[MAXN][MAXN]; // 邻接矩阵
int n;

void dfs(int u) {
    visited[u] = true;
    cout << u << " ";
    for (int v = 1; v <= n; v++) {
        if (graph[u][v] && !visited[v]) {
            dfs(v);
        }
    }
}
```

> ❗ 无“撤销”操作，只标记访问过。

---

### 2. 广度优先搜索（BFS）——最短路径
```cpp
#include <iostream>
#define MAXQ 10000
using namespace std;

int queue[MAXQ], front = 0, rear = 0;
bool visited[MAXN];
int dist[MAXN];

void bfs(int start) {
    queue[rear++] = start;
    visited[start] = true;
    dist[start] = 0;
    
    while (front < rear) {
        int u = queue[front++];
        for (int v = 1; v <= n; v++) {
            if (graph[u][v] && !visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                queue[rear++] = v;
            }
        }
    }
}
```

> ⚠️ 使用手写队列（C++98 无 `queue` 也可，但通常允许 `<queue>`；若禁 STL 则手写）。

---

### 3. 回溯算法 —— N 皇后（P1219）
```cpp
// 全局状态
bool col_used[14] = {0};
bool diag1[30] = {0}; // row - col + n
bool diag2[30] = {0}; // row + col
int path[14];         // 当前解（非 vector，更 C++98 友好）
int total = 0, n;

void backtrack(int row) {
    if (row > n) {
        total++;
        if (total <= 3) {
            for (int i = 1; i <= n; i++) {
                if (i > 1) cout << " ";
                cout << path[i];
            }
            cout << '\n';
        }
        return;
    }

    for (int c = 1; c <= n; c++) {
        int d1 = row - c + n;
        int d2 = row + c;
        if (!col_used[c] && !diag1[d1] && !diag2[d2]) {
            // 1. 做选择
            col_used[c] = diag1[d1] = diag2[d2] = true;
            path[row] = c;

            // 2. 递归
            backtrack(row + 1);

            // 3. 撤销选择 ←←← 回溯的核心！
            col_used[c] = diag1[d1] = diag2[d2] = false;
        }
    }
}
```

> ✅ **回溯三步曲**：  
> ① 做选择 → ② 递归 → ③ 撤销选择

---

## 四、典型应用场景

| 问题类型             | 推荐算法 | 原因                     |
| -------------------- | -------- | ------------------------ |
| 迷宫是否有解？       | DFS      | 快速深入，找到任意解即可 |
| 迷宫最短路径？       | BFS      | 层序保证首次到达即最短   |
| N 皇后、数独、全排列 | 回溯     | 需要构造完整解并验证     |
| 图是否连通？         | DFS/BFS  | 任一种都能遍历连通分量   |
| 拓扑排序             | DFS      | 利用后序遍历顺序         |
| 二分图判断           | BFS/DFS  | 染色法，两者皆可         |

---

## 五、总结口诀

- **DFS**：一条路走到底，撞墙就回头；
- **BFS**：一圈一圈往外扩，最近的先到；
- **回溯**：DFS + 记录路径 + **做完要还原**！

> 💡 在算法竞赛中：
> - 如果题目要求“输出所有方案” → **回溯**
> - 如果只要“是否存在”或“遍历” → **DFS/BFS**
> - 如果要求“最少步数” → **BFS**

---

如需进一步模板（如手写栈实现 DFS、手写队列 BFS），可继续提问！