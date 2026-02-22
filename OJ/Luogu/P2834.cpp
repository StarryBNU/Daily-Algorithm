#include<cstdio>
using namespace std;

int n, w, a[1005], f[10005];
const int mod=1e9+7;

int main() {
    scanf("%d%d", &n, &w);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    
    f[0] = 1;
    for (int j = 1; j <= n; j++)         
        for (int i = a[j]; i <= w; i++)   
            f[i] = (f[i] + f[i - a[j]]) % mod;
    
    printf("%d", f[w]);
    return 0;
}
