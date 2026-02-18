//时间：2026.2.17
//tag：最小生成树 
//朴素版本 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<climits>
#include<queue>
using namespace std;
int n,m,a[5005][5005];
const int INF=0x3f3f3f3f;
template<int N>
int prim(int n,const int(&graph)[N][N])
{
	bool visited[N];
	int key[N];
	for (int i=1;i < n;i++)
	{
		visited[i]=false;
		key[i]=INF;
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	memset(a,0x3f,sizeof(a));
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		scanf("%d%d",&x,&y);
		x--,y--;
		scanf("%d",&w);
		if (w < a[x][y]) {
    		a[x][y] = a[y][x] = w;
		}
	}
	int ans=prim(n,a);
	if(ans==-1)
		printf("orz");
	else
		printf("%d",ans);
	return 0;	
}
