#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;
ll power(ll a,ll b, ll mod)
{
    if (b == 0) 
        return 1;
    ll t = power(a, b / 2, mod);         
    t = (t * t) % mod; 
    if (b % 2 == 1) 
        t = (t * a) % mod;
    return t;
} 
signed main() {
    ll n, m;
    cin >> n >> m;
    ll mu=(n-1)*(m-1);
    cout<<pow(2LL,mu,MOD);
    
}

