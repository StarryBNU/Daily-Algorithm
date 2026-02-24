/*#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,l,r,f[(int)2e5+1],a[(int)2e5+1];
int main()
{
	scanf("%d%d%d",&n,&l,&r);
	for(int i=0;i<=n;i++)
		scanf("%d",&a[i]);
	memset(f,0x3f,sizeof(f));
	f[0]=a[0];
	for(int i=l;i<=n+r-1;i++)
	{
		for(int j=max(0,i-r);j<=i-l;j++)
			if(f[j]!=0x3f3f3f3f)
				if(f[i]==0x3f3f3f3f)
					f[i]=f[j]+a[i];
				else
					f[i]=max(f[i],f[j]+a[i]);
	}
	int maxi=-0x3f3f3f3f;
	for(int i=n;i<=n+r-1;i++)
		if(f[i]!=0x3f3f3f3f)
			maxi=max(maxi,f[i]);
	printf("%d",maxi);
	return 0;
}
*/ 
/* 
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream> 
using namespace std;
const int N = 200010;
int n, l, r;
int a[N * 2], f[N * 2];
int dq[N * 2];
int head, tail;
int main() {
    scanf("%d%d%d", &n, &l, &r);
    for (int i= 0; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    memset(f, 0x3f, sizeof(f));
    f[0] = a[0];
    head = 0, tail = 0;
    dq[tail++] = 0; 
    for(int i=1;i<=n+r;i++) {
        while(head<tail&&dq[head]<i-r) {
            head++;
        }
        if(head< tail && dq[head] <= i - l) {
            f[i] = f[dq[head]] + a[i];
        }
        if(f[i]!=0x3f3f3f3f) {
            while (head < tail && f[dq[tail - 1]] <= f[i]) {
                tail--;
            }
            dq[tail++] = i;
        }
    }
    int maxi=-0x3f3f3f3f;
	for(int i=n;i<=n+r-1;i++)
		if(f[i]!=0x3f3f3f3f)
			maxi=max(maxi,f[i]);
	printf("%d",maxi);
    return 0;
}*/ 
#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<cstring> 
using namespace std;
const int N = 400010; 
int n, l, r;
int a[N], f[N];
int dq[N];
int main() {
    scanf("%d%d%d", &n, &l, &r);
    for (int i = 0; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i <= n + r; i++) {
        f[i] = -1000000000; 
    }
    f[0] = a[0];
    int head = 0, tail = 0;
    dq[tail++] = 0;
    for (int i = 1; i <= n + r; i++) {
        if (i >= l) {
            int j = i - l;
            if (f[j] != -1000000000) {
                while (head < tail && f[dq[tail-1]] <= f[j]) {
                    tail--;
                }
                dq[tail++] = j;
            }
        }
        while (head < tail && dq[head] < i - r) {
            head++;
        }
        if (head < tail && dq[head] <= i - l) {
            f[i] = f[dq[head]] + a[i];
        }
    }
    int ans = -1000000000;
    for (int i = n; i <= n + r; i++) {
        ans = max(ans, f[i]);
    }
    printf("%d\n", ans);
    return 0;
}
