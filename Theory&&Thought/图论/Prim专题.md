当然可以！下面是一份**朴素 Prim 算法（O(n²) 版本）** 的完整实现，适用于**稠密图**（如完全图、n ≤ 5000），并附有**逐行详细注释**，帮助你彻底理解其工作原理。

---

### ✅ 朴素 Prim 算法（邻接矩阵 + 线性扫描）

```cpp
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int MAXN = 5005;          // 最大节点数（根据题目调整）
const int INF = 0x3f3f3f3f;     // 定义“无穷大”，约 1.06e9，安全且可 memset

// 邻接矩阵存储图（全局变量，避免栈溢出）
int graph[MAXN][MAXN];

/**
 * 朴素 Prim 算法：求无向图的最小生成树（MST）总权值
 * @param n: 节点数量（节点编号 0 ~ n-1）
 * @return: MST 的总权值；若图不连通，返回 -1
 */
int prim(int n) {
    // key[i] 表示节点 i 到当前 MST 的最小边权
    vector<int> key(n, INF);
    
    // visited[i] 表示节点 i 是否已加入 MST
    vector<bool> visited(n, false);
    
    // 从节点 0 开始构建 MST
    key[0] = 0;
    
    int totalWeight = 0;   // MST 的总权值
    int nodesInMST = 0;    // 已加入 MST 的节点数

    // 主循环：共需加入 n 个节点
    for (int iter = 0; iter < n; ++iter) {
        // Step 1: 在未访问的节点中，找出 key 最小的节点 u
        int u = -1;
        for (int v = 0; v < n; ++v) {
            if (!visited[v] && (u == -1 || key[v] < key[u])) {
                u = v;
            }
        }

        // 如果找不到未访问的节点，说明图不连通
        if (u == -1 || key[u] == INF) {
            return -1; // 无法构成生成树
        }

        // Step 2: 将节点 u 加入 MST
        visited[u] = true;
        totalWeight += key[u];
        nodesInMST++;

        // Step 3: 更新 u 的所有邻居 v 的 key 值
        // 即：尝试用边 (u, v) 来改进 v 到 MST 的连接
        for (int v = 0; v < n; ++v) {
            if (!visited[v] && graph[u][v] != INF) {
                // 如果通过 u 到 v 的边更短，则更新 key[v]
                if (graph[u][v] < key[v]) {
                    key[v] = graph[u][v];
                }
            }
        }
    }

    // 理论上 nodesInMST == n，但为保险起见仍可检查
    return (nodesInMST == n) ? totalWeight : -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    // 初始化邻接矩阵：全部设为 INF（表示无边）
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            graph[i][j] = INF;
        }
        graph[i][i] = 0; // 自环设为 0（不影响算法）
    }

    // 读入边（处理重边：保留最小权值）
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--; // 转为 0-based 编号

        // 无向图：双向存边
        // 注意：可能存在重边，取最小值
        if (w < graph[u][v]) {
            graph[u][v] = graph[v][u] = w;
        }
    }

    int ans = prim(n);
    if (ans == -1) {
        cout << "orz\n"; // 图不连通
    } else {
        cout << ans << '\n';
    }

    return 0;
}
```

---

## 🔍 算法核心思想详解

### 🌳 1. **MST 构建过程**
- 从任意节点（如 0）开始，逐步扩展 MST
- 每次选择**连接 MST 与非 MST 部分的最小权边**
- 直到包含所有 `n` 个节点

### 📦 2. **关键数组作用**
| 数组         | 含义                                                         |
| ------------ | ------------------------------------------------------------ |
| `key[v]`     | 当前已知的、从节点 `v` 到 MST 的最小边权（初始为 INF，起点为 0） |
| `visited[v]` | 标记 `v` 是否已加入 MST                                      |

### 🔁 3. **主循环三步走**
1. **选点**：线性扫描找 `key` 最小的未访问节点 `u`
2. **加入**：将 `u` 加入 MST，累加 `key[u]`
3. **松弛**：用 `u` 更新所有邻居 `v` 的 `key[v]`

> 这和 Dijkstra 很像，但 Dijkstra 的 `key` 是到起点的距离，Prim 的 `key` 是到 MST 的最小边权。

---

## ⚙️ 为什么叫“朴素”？

- 因为“选最小点”用的是 **O(n) 线性扫描**，而非堆优化
- 虽然慢，但在**稠密图**（m ≈ n²）上比堆优化更快（常数小、缓存友好）

---

## ✅ 适用场景

- 节点数 `n ≤ 5000`
- 图是稠密的（如完全图、网格图）
- 需要稳定、简单、不易错的实现

---

## 📌 注意事项

1. **初始化 `graph` 为 INF**：表示无边
2. **处理重边**：保留最小权值
3. **节点编号转 0-based**：便于数组操作
4. **判断图是否连通**：若某轮找不到有效 `u`，返回 -1

---

这份代码可直接用于 **洛谷 P3366【模板】最小生成树**，且在 `n=5000` 时运行高效（约 0.5s 内）。

如需堆优化版本或 Kruskal，也可以告诉我！