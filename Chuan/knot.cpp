#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=2222;

int n;
vector<int> g[maxn], res;
int d[maxn];

int lis(int l, int r)
{
	vector<int>a;
    for (int i=l; i<r; i++)
    {
    	auto it=upper_bound(a.begin(), a.end(), res[i]);
    	if (it!=a.end()) *it=res[i];
    	else a.push_back(res[i]);
    }
    return a.size();
}

void dfs(int x, int p)
{
	for (auto u:g[x])
	{
		if (u==p) continue;
		if (d[u])
		{
			res.push_back(x);
			while (res.back()!=u)
			{
				res.push_back(d[res.back()]);
			}
			vector<int> tmp(2*res.size());
			for (int i=0; i<n; i++) tmp[i]=res[i];
			for (int i=n; i<2*n; i++) tmp[i]=res[i-n];
//			for (int i=0; i<2*n; i++) cout<<tmp[i]<<" "; 
			if (tmp.size()!=2*n) cout<<-1;
			else
			{
				int real_lis=0;
				for (int i=0; i<tmp.size(); i++)
				{
					real_lis=max(real_lis, lis(i, i+n));
				}
				int mn=real_lis;
				cout<<mn<<endl;
				real_lis=0;
				reverse(tmp.begin(), tmp.end());
				for (int i=0; i<tmp.size(); i++)
				{
					real_lis=max(real_lis, lis(i, i+n));
				}
				cout<<real_lis<<endl;
				mn=min(mn, real_lis);
				cout<<n-mn<<endl;
			}
			exit(0);
		}
		d[u]=x;
		dfs(u, x);
	}
}

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	if (fopen("knot.inp", "r"))
	{
		freopen("knot.inp", "r", stdin);
		freopen("knot.out", "w", stdout);
	}
	cin >> n;
	for (int i=1; i<=n; i++)
	{
		int a, b; cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i=1; i<=n; i++)
	{
		if (!d[i])
		{
			d[i]=i;
			dfs(i, 0);
		}
	}
}
//5 2 3 6 4 1

