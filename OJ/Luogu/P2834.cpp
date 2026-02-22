#include<cstdio>
using namespace std;

int n, w, a[1005], f[10005];
const int mod = 10000;  // 注意：P2834 模 10000！

int main() {
    scanf("%d%d", &n, &w);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    
    f[0] = 1;
    for (int j = 1; j <= n; j++)          // 外层：纸币种类
        for (int i = a[j]; i <= w; i++)   // 内层：金额从 a[j] 到 w
            f[i] = (f[i] + f[i - a[j]]) % mod;
    
    printf("%d", f[w]);
    return 0;
}
