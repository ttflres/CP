#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+7;

int n, q, a, b, c=1, d[maxn], in[maxn], out[maxn];
vector<set<int>> g(maxn);
map<pair<int, int>, int> mp;

void dfs(int x)
{
	d[c]=x;
	in[x]=c++;
	for (auto V:g[x])
	{
		dfs(V);
	}
	out[x]=c;
}

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> q;
	for (int i=1; i<n; i++)
	{
		cin >> a >> b >> c;
		g[a].insert(b);
		g[b].insert(a);
	}
	dfs(1);
	for (int i=1; i<=q; i++)
	{
		int x, y; cin >> x >> y;
		if (y>out[x]-in[x]) cout<<"-1"<<endl;
		else cout<<d[in[x]+y-1]<<endl;
	}
}
