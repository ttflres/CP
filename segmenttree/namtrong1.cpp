#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+7;

struct range
{
	int x, y, id;
	bool operator < (const range &o)
	{
		if (x==o.x) return y>o.y;
		else return x<o.x;
	}	
} a[maxn];

int n, st[4*maxn];
int res[maxn];

void update(int id, int l, int r, int u)
{
	if (l > u || r < u) return;
	if (l==r&&l==u)
	{
		st[id]+=1;
		return;
	}
	int mid=(l+r) / 2;
	if (u<=mid) update(id*2, l, mid, u);
	else update(id*2+1, mid+1, r, u);
	st[id] = st[id*2] + st[id*2+1];
}
 
int get(int id, int l, int r, int u, int v)
{
	if (l > v || r < u) return 0;
	if (l >= u && r <= v) return st[id];
	int mid = (l+r) / 2;
	return get(id*2, l, mid, u, v) + get(id*2+1, mid+1, r, u, v);
}

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i=1; i<=n; i++)
	{
		cin >> a[i].x >> a[i].y;
		a[i].id=i;
	}
	sort(a+1, a+n+1);
//	for (int i=1; i<=n; i++) cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].id<<endl;
	for (int i=1; i<=n; i++)
	{
		vector<int> v;
		while (a[i+1].x==a[i].x&&a[i].y==a[i+1].y)
		{
			v.push_back(i);
			update(1, 1, maxn, a[i].y);
			i++;
		}
		res[a[i].id]=get(1, 1, maxn, a[i].y, maxn);
		if (v.size())
		{
			for (auto x:v)
			{
				res[a[x].id]=res[a[i].id];		
			}
		}
		update(1, 1, maxn, a[i].y);
	}
	for (int i=1; i<=n; i++) cout<<res[i]<<endl;
}
