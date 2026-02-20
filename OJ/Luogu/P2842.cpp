#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;
int n,w,a[1005],f[10005];
int main()
{
	scanf("%d%d",&n,&w);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	for(int i=1;i<=w;i++)
	{
		for(int j=1;j<=n;j++)
			f[i]=min(f[i],f[i-a[j]]+1);
	}
} 
