#include<cmath>
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long binpow(long long a, long long b, long long p) {
  if (b == 0) return 1;
  long long res = binpow(a, b / 2, p);
  if (b % 2)
    return res * res % p * a % p;
  else
    return res * res % p;
}
int main()
{
	long long a,b,p;
	scanf("%lld%lld%lld",&a,&b,&p);
	printf("%lld^%lld mod %lld=%lld",a,b,p,binpow(a,b,p));
	return 0;
}

