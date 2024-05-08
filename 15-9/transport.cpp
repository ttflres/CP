#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=2e5+7;

int n, m;
vector<pair<int, int>> g[maxn];
int d[maxn];

bool bfs(int mid)
{
	for (int i=1; i<=n; i++) d[i]=0;
	queue<int> q;
	q.push(1);
	d[1]=1;
	while (!q.empty())
	{
		int u=q.front();
		q.pop();
		for (auto x:g[u])
		{
			if (mid<=x.first&&d[x.second]==0)
			{
				d[x.second]=1;
				q.push(x.second);
			}
		}
	}
	if (d[n]) return true;
	return false;
}

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i=1; i<=m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({w, v});
		g[v].push_back({w, u});
	}
	int l=0, r=1e9, ans=-1; 
	while (l<=r)
	{
		int mid=(l+r)/2;
		if (bfs(mid))
		{
			ans=mid;
			l=mid+1;
		} else r=mid-1;
	}
	cout<<ans;
}

