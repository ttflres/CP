#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+7;

int n, m, t;
pair<int, int> g[maxn];
int p[maxn], pf[maxn];

bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first==b.first) return a.second<b.second;
    else return a.first<b.first;
}

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   freopen("vetc.inp", "r", stdin);
   freopen("vetc.out", "w", stdout);
   cin >> n >> m >> t;
   for (int i=1; i<=n; i++)
   {
       cin >> g[i].first >> g[i].second;
   }
   sort(g+1, g+n+1, cmp);
   /*for (int i=1; i<=n; i++)
   {
       cout<<g[i].first<<" "<<g[i].second<<endl;
   }*/
   for (int i=1; i<=n; i++) pf[i]=pf[i-1]+g[i].second;
   for (int i=1; i<=m; i++)
   {
       cin >> p[i];
       auto it=upper_bound(pf+1, pf+n+1, p[i])-pf;
       if (it>n) cout<<t<<" ";
       else cout<<g[it].first<<" ";
   }

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