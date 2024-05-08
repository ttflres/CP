#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5+7;

int t, n, a[2][maxn], dp[2][maxn], u, v;
vector<int>g[maxn];

void dfs(int x, int y=-1)
{
	dp[0][x]=dp[1][x]=0;
	for (auto t:g[x])
	{
		if (t==y) continue;
		dfs(t,x);
		dp[0][x]+=max(abs(a[0][x]-a[1][t])+dp[1][t], abs(a[0][x]-a[0][t])+dp[0][t]);
		dp[1][x]+=max(abs(a[1][x]-a[1][t])+dp[1][t], abs(a[1][x]-a[0][t])+dp[0][t]);
	}	
}

void solve()
{
	cin >> n;
	fill(g + 1, g + n + 1, vector<int>());
	for (int i=1; i<=n; i++)
	{
		cin >> a[0][i] >> a[1][i];
	}
	for (int i=1; i<n; i++)
	{
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	cout<<max(dp[0][1], dp[1][1])<<endl;
}

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	t=1;
	while (t--) solve();
}

