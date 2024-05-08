#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1000000;

int n, mod;
vector<int> g[maxn];
int sz[maxn];
int p[maxn];

void sieve()
{
	for (int i=2; i*i<=maxn; i++)
	{
		if (p[i]==0)
		{
			for (int j=i*i; j<=maxn; j+=i)
			{
				if (p[j]==0)
				p[j]=i;
			}
		}
	}
	for (int i=2; i<=maxn; i++) if (p[i]==0) p[i]=i;
}

int dfs(int u, int p)
{
	sz[u]=1;
	for (auto x:g[u])
	{
		if (x!=p)
		{
			sz[u]+=dfs(x, u);
		}
	}
	return sz[u];
}

int pa[maxn], pb[maxn];

int mul(int a, int b, int mod)
{
	if (b==0) return 1;
	int t=mul(a, b/2, mod);
	t=(t*t)%mod;
	if (b&1) return (t*a)%mod;
	return t%mod;
}

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	if (fopen("counting.inp", "r"))
	{
		freopen("counting.inp", "r", stdin);
		freopen("counting.out", "w", stdout);
	}
	sieve();
	cin >> n >> mod;
	for (int i=2; i<=n; i++)
	{
		int x; cin >> x;
		g[x].push_back(i);
		g[i].push_back(x);
	}
	dfs(1, 0);
	int m=1, t=1;
	for (int i=2; i<n; i++)
	{
		int x=i;
		while (x!=1)
		{
			pa[p[x]]++;
			x/=p[x];
		}
	}
	for (int i=2; i<=n; i++)
	{
		if (sz[i]>1)
		{
			int x=sz[i];
			while (x!=1)
			{
				pb[p[x]]++;
				x/=p[x];
			}
		}
	}
	int ans=1;
	for (int i=1; i<=maxn; i++)
	{
		ans*=mul(i, pa[i]-pb[i], mod);
		ans%=mod;
	}
	cout<<ans;
}
