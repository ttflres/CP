#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=5e5+7;
const int mod=1e9+7;

int n, m, a[maxn];
vector<int> g[maxn], ln;
int d[maxn];

namespace sub2
{
	int d[maxn], l[maxn];
	int crr[maxn];
	
	void bfs(int x)
	{
//		d[x]=1;
		l[x]=0;
		queue<int> q;
		q.push(x);
		while (!q.empty())
		{
			int u=q.front();
			q.pop();
			bool flag=true;
			for (auto v:g[u])
			{
				if (a[v]>a[u]&&a[v]-a[u]>crr[u])
				{
//					cout<<u<<" "<<v<<" "<<a[u]<<" "<<a[v]<<endl;
					flag=false;
//					cout<<u<<" "<<v<<endl;
					crr[v]=a[v]-a[u];
					l[v]=l[u]+1;
					q.push(v);
				}
			}
			if (flag) crr[u]=0;
		}
	}
	
	void solve()
	{
		int ans=0, cnt=0;
		for (int i=1; i<=n; i++)
		{
			bfs(i);
			for (int i=1; i<=n; i++) 
			{
				if (l[i]>ans)
				{
					ans=l[i];
					cnt=0;
				}
				if (l[i]==ans) cnt++;
			}
			memset(crr, 0, sizeof(crr));
			memset(l, 0, sizeof(l));
//			cout<<"-----------"<<endl;
		}
		if (ans==1) cout<<ans<<endl<<cnt%mod;
		else cout<<ans+1<<endl<<cnt%mod;
	}
}

namespace sub3
{
	void solve()
	{
		ln.erase(unique(ln.begin(), ln.end()), ln.end());
//		for (auto x:ln) cout<<x<<" ";
//		cout<<endl;
		int mx=0, cnt=0, crr=0;
		map<int, int> mp;
		for (int i=0; i<ln.size()-1; i++)
		{
			if (a[ln[i]]<a[ln[i+1]]&&a[ln[i+1]]-a[ln[i]]>crr)
			{
//				cout<<a[ln[i]]<<" "<<a[ln[i+1]]<<" "<<crr<<endl;
				crr=a[ln[i+1]]-a[ln[i]];
				cnt++;
				if (cnt>mx)
				{
					mx=cnt;
					mp[mx]++;
				}
			}
			else
			{
				cnt=0, crr=0;
			}
		}
		if (mx==0) cout<<mx<<endl<<mp[mx]%mod;
		else cout<<mx+1<<endl<<mp[mx]%mod;
	}
}

void dfs(int u)
{
	d[u]=1;
	for (auto x:g[u]) if (!d[x]) dfs(x);
}

bool check()
{
	int lt=0;
	for (int i=1; i<=n; i++)
	{
		if (!d[i])
		{
			dfs(i);
			lt++;
		}
	}
	bool flag=true;
	for (int i=1; i<=n; i++)
	{
		if (g[i].size()>2) flag=false;
	}
	if (lt==1&&m==n-1&&flag) return true;
	return false;
}

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("dincpath.inp", "r", stdin);
	freopen("dincpath.out", "w", stdout); 
	cin >> n >> m;
	for (int i=1; i<=n; i++) cin >> a[i];
	for (int i=1; i<=m; i++)
	{
		int u, v; cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
		ln.push_back(u);
		ln.push_back(v);
	}
	if (check()) sub3::solve();
	else sub2::solve();
}

