#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
const int mod=100003;
int a[10000000];
int n,k;
int dfs(int x){
	int ans=0;
	if(a[x]!=-1)
		return a[x];
	else
	{
	if(x>1&&x<=k)
	{
		ans=1;
		for(int i=1;i<x;i++)
			ans+=dfs(i);
		return a[x]=ans%mod;
	}
	else if(x>k)
	{
		for(int i=x-1;i>=x-k;i--)
			ans+=dfs(i);
		return a[x]=ans%mod;
	}
	}
}
int main()
{
	std::memset(a, -1, sizeof(a));
	a[1]=1;
	scanf("%d%d",&n,&k);
	int res=dfs(n%mod);
	printf("%d\n",res);
	return 0;
} 
