#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;
//moi so tru n co 2 cach dat
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
    ll t;
    cin >> t;
    while (t--)
    {
    ll n;
    cin >> n;
    if (n<3) cout<<0;
    else cout<<power(2LL,(n-1),mod)-2;   
    }
   
    
}