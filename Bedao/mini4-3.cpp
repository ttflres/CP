#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+7, mod=1e9+7;

int t, n, a[maxn], ans=1, k;
int fact[maxn], invfact[maxn];


int power(int a, int b, int mod)
{
    if (b == 0) return 1;
    int t = power(a, b / 2, mod);         
    t = (t * t) % mod; 
    if (b % 2 == 1) t = (t * a) % mod;
    return t;
} 


signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    fact[0]=1;
    invfact[0]=1;
    for (int i=1; i<=maxn; i++)
    {
        fact[i]=(fact[i-1]*i)%mod;
        invfact[i]=power(fact[i], mod-2, mod);
    }
    cin >> n >> k;
    for (int i=1; i<=k; i++) cin >> a[i];
    ans*=fact[n];
    for (int i=1; i<=k; i++) ans*=invfact[a[i]], ans%=mod;
    cout<<ans%mod;
}
