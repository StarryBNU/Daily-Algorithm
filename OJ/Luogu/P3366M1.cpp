#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct DSU {
    vector<int> parent;
    vector<int> rank;

    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) {
            return false;
        }
        if (rank[x] < rank[y]) {
            parent[x] = y;
        } else if (rank[x] > rank[y]) {
            parent[y] = x;
        } else {
            parent[y] = x;
            rank[x]++;
        }
        return true;
    }
};

struct Edge {
    int u, v, w;
    Edge(int u_, int v_, int w_) : u(u_), v(v_), w(w_) {}
    
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

long long kruskal(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());

    DSU dsu(n);
    long long totalWeight = 0;
    int edgesUsed = 0;

    for (int i = 0; i < (int)edges.size(); ++i) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;

        if (dsu.unite(u, v)) {
            totalWeight += w;
            edgesUsed++;
            if (edgesUsed == n - 1) {
                break;
            }
        }
    }

    if (edgesUsed == n - 1) {
        return totalWeight;
    } else {
        return -1;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<Edge> edges;
    edges.reserve(m); 

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--; 
        edges.push_back(Edge(u, v, w)); 
    }

    long long ans = kruskal(n, edges);

    if (ans == -1) {
        cout << "orz\n";
    } else {
        cout << ans << '\n';
    }

    return 0;
}
