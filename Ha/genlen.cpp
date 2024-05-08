#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e6+7;

int n;
vector<int> g[maxn];
int diff[maxn], d[maxn], cnt=0, crr=0;
int vis[maxn];

void dfs(int u)
{
	d[u]=1;
	if (diff[u]>0) cnt+=diff[u];
	for (auto x:g[u])
	{
		if (d[x]==0)
		{
			dfs(x);
		}
	}
}

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	if (fopen("genlen.inp", "r"))
	{
		freopen("genlen.inp", "r", stdin);
		freopen("genlen.out", "w", stdout);
	}
	cin >> n;
	for (int i=1; i<=n; i++)
	{
		int u, v; cin >> u >> v;
		diff[u]++, diff[v]--;
		g[u].push_back(v);
		g[v].push_back(u);
		vis[u]=vis[v]=1;
	}
	for (int i=1; i<=n; i++)
	{
		if (!d[i]&&vis[i])
		{
			cnt=0;
			dfs(i);
			crr+=max(1ll, cnt);
		}
	}
	cout<<crr+n;
	
}

