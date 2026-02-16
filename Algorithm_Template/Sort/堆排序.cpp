//这是针对P1227的模板题的代码，事实上也说明选择排序的时间复杂度n方还是太大了 
//于是改为堆排序 
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
using namespace std; 
long long a[1000000];
void sift_down(long long* arr,int start,int end)
{
	int parent=start;
	int child=parent*2+1;
//我仍然不理解为什么child<=end 
	while(child<=end)
	{
		if (child + 1 <= end && arr[child] < arr[child + 1]) child++;
		if (arr[parent] >= arr[child])
      		return;
      	else{  
      		swap(arr[parent], arr[child]);
      		parent = child;
      		child = parent * 2 + 1;
    	}	
	}
}
void heap_sort(long long* arr,int len)
{
	for (int i = (len - 1 - 1) / 2; i >= 0; i--) 
		sift_down(arr, i, len - 1);
//这一步是建堆 
	for (int i = len - 1; i > 0; i--) {
    	swap(arr[0], arr[i]);
    	sift_down(arr, 0, i - 1);
  }
//这一步是排序 
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%lld",&a[i]);
	heap_sort(a,n);
	for(int i=0;i<n;i++)
		printf("%lld ",a[i]);
	return 0;
	
}
