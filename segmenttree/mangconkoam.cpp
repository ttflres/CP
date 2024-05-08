#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e5 + 7;
int n, st[4*maxn];
int ans[maxn];
int q, a[maxn], pf[maxn];

void build(int id, int l, int r)
{
	if(l == r)
	{
		st[id] = 0;
		return;
	}
	int m = (l+r) / 2;
	build(id*2, l, m);
	build(id*2+1, m+1, r);
	st[id] = st[id*2] + st[id*2+1];
}

void update(int id, int l, int r, int u)
{
	if (l > u || r < u) return;
	if (l == r)
	{
		st[id] = 1;
		return;
	}
	int m = (l+r) / 2;
	update(id*2, l, m, u);
	update(id*2+1, m+1, r, u);
	st[id] = st[id*2] + st[id*2+1];
}

int get(int id, int l, int r, int u, int v)
{
	if (l > v || r < u) return 0;
	if (l >= u && r <= v) return st[id];
	int m = (l+r) / 2;
	return get(id*2, l, m, u, v) + get(id*2+1, m+1, r, u, v);
}

signed main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n;
	pair<int, int> p[n+1];
	int ans=0;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		pf[i]=pf[i-1]+a[i];
		if (pf[i]>=0) ans++;
		p[i].first=pf[i], p[i].second = i;
	} 
	sort(p+1, p+n+1);
	for(int i = 1; i <= n; i++)
	{
		ans+=get(1, 1, n, 1, p[i].second-1);
		update(1, 1, n, p[i].second);
		//cout<<get(1, 1, n, 1, i)<<endl;
	}
	cout<<ans;
}
