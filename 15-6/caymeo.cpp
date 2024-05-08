#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair <int, int>
const int maxn = 1e5+7;
int n, m, ans, x, y, c[maxn];
vector<int>a[maxn];
void dfs(int x, int p, int cnt)
{
   if (cnt>m) return;
   int ok=1;
   for (int i=0; i<a[x].size(); i++)
   {
      if (a[x][i]==p) continue;
      ok=0;
      dfs(a[x][i], x, cnt*c[a[x][i]]+c[a[x][i]]);
   }
   ans+=ok;
   //cout<<ans<<endl;
}
signed main()
{
    ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cin >> n >> m;
   for (int i=0; i<n; i++) cin >> c[i];
   for (int i=0; i<n-1; i++)
   {
      cin >> x >> y;
      x--, y--;
      a[x].push_back(y);
      a[y].push_back(x);
   }
   dfs(0,-1,c[0]);
   cout<<ans;
}
