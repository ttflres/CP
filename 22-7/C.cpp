#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn=1e5+7, mod=1e9+7;

int n, m, k;
int f[45][45], g[45][45];
int fact[maxn], invfact[maxn];

int power(int a, int b, int mod)
{
    if (b == 0) return 1;
    int t = power(a, b / 2, mod);
    t = (t * t) % mod;
    if (b % 2 == 1) t = (t * a) % mod;
    return t;
}

int C(int n, int k) {
    if (k > n) return 1;
    return fact[n] * invfact[k] % mod * invfact[n - k] % mod;
}

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   cin >> n >> m >> k;
   for (int t=0; t<n; t++)
   {
       for (int j=0; j<n; j++)
       {
           for (int x=0; x<=k; x++)
           {
               //if (n-t<=x&&t<=j-x)
               cout<<C(x, n-t)*C(j-x, t)<<endl;
               //cout<<g[t][j]<<endl;
           }
       }
   }
}