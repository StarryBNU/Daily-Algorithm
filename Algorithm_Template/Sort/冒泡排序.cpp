//尝试采用结构体，class，这些有意义吗
//似乎多尝试几种排序算法会更有意义一点，喵~
//干脆都写一遍吧
//基于P1068 
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std; 
int n,m;
int k[5001],s[5001];
void Readin()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    	scanf("%d%d",&k[i],&s[i]);
}
void bubble_sort() {
  bool flag = true;
  while (flag) {
    flag = false;
    for (int i = 1; i < n; ++i) {
    	if ((s[i] < s[i + 1])||(s[i]==s[i+1]&&k[i]>k[i+1])) 
	  	{
        flag = true;
        swap(s[i],s[i+1]);
        swap(k[i],k[i+1]);
		}
    }
  }
}
void PrintOut()
{
	int RankLine=m*1.5;
	int ScoreLine=s[RankLine];
	while(1)
	{
		if(s[RankLine]==ScoreLine)
			RankLine++;
		else
			break;
	}
	RankLine--;
	printf("%d %d\n",ScoreLine,RankLine);
	for(int i=1;i<=RankLine;i++)
		printf("%d %d\n",k[i],s[i]);
}
int main()
{
    Readin();
    bubble_sort();
    PrintOut();
    return 0;
}
