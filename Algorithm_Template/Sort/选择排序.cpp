//这是针对P1227的模板题的代码，事实上也说明选择排序的时间复杂度n方还是太大了 
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std; 
void Select_Sort(long long* a,long long n)
{
	for(int i=1;i<n;i++)
	{
		int ith=i;
		for(int j=i;j<=n;j++)
			if(a[ith]>a[j])
				ith=j;
		swap(a[ith],a[i]);
	}
}

int main()
{
	long long n,a[1000000];
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	Select_Sort(a,n);
	for(int i=1;i<=n;i++)
		printf("%lld ",a[i]);
	return 0;
	
}
