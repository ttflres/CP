#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+7;

int n;
int cnt=1, mx=1;
vector<pair<int, int>> v;
int d[maxn];
bool flag=true;

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   freopen("island.inp", "r", stdin);
   freopen("island.out", "w", stdout);
   cin >> n;
   d[0]=1; d[n+1]=1;
   for (int i=1; i<=n; i++)
    {
        int x;
        cin >> x;
        if (x!=0) flag=false;
        v.push_back({x, i});
    }
   sort(v.begin(), v.end());
   for (int i=0; i<v.size(); i++)
   {
        d[v[i].second]=1;
        if (d[v[i].second-1]==0&&d[v[i].second+1]==0) cnt++;
        else if (d[v[i].second-1]==1&&d[v[i].second+1]==1) cnt--;
        if (v[i+1].first!=v[i].first) mx=max(mx, cnt);
        //cout<<mx<<endl;
    }
    if (flag) cout<<0;
    else cout<<mx;
}
/*
==================================================+
INPUT
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/