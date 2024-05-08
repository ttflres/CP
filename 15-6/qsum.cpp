#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair <int, int>
const int maxn = 1e5+7;
ll n, q;
ll a[maxn], pf[maxn], pfs[maxn], sum;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    for (int i=1; i<=n; i++)
    {
        cin >> a[i];
        pf[i]=pf[i-1]+a[i];
        pfs[i]=pfs[i-1]+a[i]*i;
    }
    sum=pfs[n];
    for (int i=1; i<=q; i++)
    {
        int l, r;
        cin >> l >> r;
        //cout<<sum<<endl;
        //cout<<pfs[l-1]<<" "<<pfs[n]-pfs[r]<<endl;
        //cout<<(l-1)*(pf[r]-pf[l-1])<<endl;
        cout<<sum-pfs[l-1]-(pfs[n]-pfs[r])-(l-1)*(pf[r]-pf[l-1])<<endl;
    }
}
