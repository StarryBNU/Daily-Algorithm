#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std; 
int n,m,a[5005][5005];
const int INF=0x3f; 
template<int N>
int prim(int n, const int (&graph)[N][N]) {
    bool visited[N];
    int key[N];
    for (int i = 0; i < n; ++i) {
        visited[i] = false;
        key[i] = INF;
    }
    key[0] = 0;

    std::priority_queue<std::pair<int, int>,
                        std::vector<std::pair<int, int> >,
                        std::greater<std::pair<int, int> > > pq;
    pq.push(std::make_pair(0, 0));

    int totalWeight = 0;
    int nodesInMST = 0;

    while (!pq.empty() && nodesInMST < n) {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();

        if (visited[u]) continue;

        visited[u] = true;
        totalWeight += w;
        ++nodesInMST;

        for (int v = 0; v < n; ++v) {
            if (!visited[v] && graph[u][v] != INF && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
                pq.push(std::make_pair(key[v], v));
            }
        }
    }

    return (nodesInMST == n) ? totalWeight : -1;
}
int main()
{
	scanf("%d%d",&n,&m);
	memset(a, 0x3f, sizeof(a));
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--,y--;
		scanf("%d",&a[x][y]);
		a[y][x]=a[x][y];
	}
	int ans=prim(n,a);
	if(ans==-1)
		printf("orz");
	else
		printf("%d",ans);
	return 0;
	
	
}
