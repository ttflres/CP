#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mn=1e7;

int n, m, pa[mn], pb[mn], x, pc[mn], mod;
int sub, t;

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

int prime[mn];
void sieve(){
    for(int i = 2;i <= mn;i++) prime[i] = i;
    for(int i = 2; i <= sqrt(mn);i++){
        if(prime[i] == i){
            for(int j = 2 *i;j <= mn;j+=i) prime[j] = i;
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    sieve();
    cin >> sub >> t >> mod;
    while (t--)
    {
    memset(pa,0,sizeof(pa));
    memset(pb, 0, sizeof(pb));
    cin >> n >> m;
    for(int i = n-m+1;i <= n;i++){
        x=i;
        while(x != 1){
            pa[prime[x]]++;
            x/=prime[x];
        }
    }
    for(int i = 1;i <= m;i++){
        x=i;
        while(x != 1){
            pb[prime[x]]++;
            x/=prime[x];
        }
    }
    ll res = 1;
    for(int i = 2;i <= mn;i++){
        int p = pa[i]-(pb[i]);
        res *= power(i,p, mod);
        res = res % mod;
    }
    cout << res % mod<<endl;
    }
}
