#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+7;

int n;
vector<int> g[maxn];
int c[maxn], d[maxn];
int f[maxn][2];

void dfs(int x)
{
	d[x]=1;
	for (auto v:g[x])
	{
		if (!d[v])
		{
			dfs(v);
			f[x][0]+=max(f[v][0], f[v][1]);
			f[x][1]+=f[v][0];
		}
	}
}

int totrc[maxn];
vector<int> trc;

void trace(int x, int state)
{
	if (state==1) trc.push_back(x);
	d[x]=1;
	for (auto v:g[x])
	{
		if (!d[v])
		{
			if (state==1) trace(v, 0);
			else
			{
				if (f[v][0]>f[v][1]) trace(v, 0);
				else trace(v, 1);
			}
		}
	}
}

int st;

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i=1; i<=n; i++)
	{
		int b; cin >> b >> c[i];
		if (b==0) st=i;
		g[b].push_back(i);
		g[i].push_back(b);
	}
	for (int i=1; i<=n; i++) f[i][1]=c[i];
	dfs(st);
	memset(d, 0, sizeof(d));
	if (f[st][0]>f[st][1]) trace(st, 0);
	else trace(st, 1);
	cout<<trc.size()<<" "<<max(f[st][0], f[st][1])<<endl;
	for (auto x:trc) cout<<x<<endl;
//	cout<<f[st][0]<<" "<<f[st][1];
}

