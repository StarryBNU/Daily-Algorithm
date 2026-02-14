#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std;
long long a[100001],mex;
int t,n;
void find_mex()
{
	mex=0;
	bool f=false;
	while(!f)
	{
		for(int i=1;i<=n;i++)
			if(mex==a[i])
			{
				mex++;
				f=true;
				break;
			}
		f=!f;	
	}
}
int main()
{
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%d",n)
		for(int j=1;j<=n;j++)
			scanf("%lld",a[i]);
		find_mex();
		
		
	}
} 
