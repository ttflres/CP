#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e5 + 7;
int n, st[4*maxn];
int ans[maxn];
int q;

struct query
{
	int l, r, k, id;
};

bool cmp (query x, query y) 
{
	return x.k < y.k;
}

void build(int id, int l, int r)
{
	if(l == r)
	{
		st[id] = 1;
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
		st[id] = 0;
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
	cin >> n >> q;
	pair<int, int> p[n+1];
	query Q[q+1];
	for(int i = 1; i <= n; i++) cin >> p[i].first, p[i].second = i;
	sort(p+1, p+n+1);
	for(int i = 1; i <= q; i++) cin >> Q[i].l >> Q[i].r >> Q[i].k, Q[i].id = i;
	sort(Q+1, Q+q+1, cmp);
	build(1, 1, n);
	int index = 1;
	for(int i = 1; i <= q; i++)
	{
		while(p[index].first <= Q[i].k)
		{
			update(1, 1, n, p[index].second);
			index++;
		}
		ans[Q[i].id] = get (1, 1, n, Q[i].l, Q[i].r);
	}
	for(int i = 1; i <= q; i++) cout << ans[i] << "\n";
}
