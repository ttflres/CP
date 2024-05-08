#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+7;

int n, k, t=0, cnt=0;
map<int, int> mp;

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("DC.inp", "r", stdin);
    freopen("DC.out", "w", stdout);
    cin >> n >> k;
    for (int i=1; i<=n; i++)
    {
        int a, b; cin >> a >> b;
        mp[a]++;
        mp[b+1]--;
    }
    mp[0]=0;
    for (auto x:mp)
    {
        mp[x.first]+=mp[t];
        if(mp[t]==k) cnt+=x.first-t;
        t=x.first;
    }
    cout<<cnt;
}
