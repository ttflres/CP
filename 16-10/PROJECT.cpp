#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

const int maxn=1e4+7;

int n, m; 
int pa[maxn], sz[maxn];
int u[maxn], v[maxn], c[maxn], l[maxn];
vector<int> g;
 
void init()
{
	for (int i=1; i<=n; i++) 
	{
		pa[i]=i;
		sz[i]=1;
	}
}
 
int find_set(int u)
{
	return (u==pa[u])?u:pa[u]=find_set(pa[u]);
}
 
bool unite(int u, int v)
{
	u=find_set(u), v=find_set(v);
	if (u==v) return false;
	if (u!=v)
	{
		if (sz[u]<sz[v]) swap(u, v);
		sz[u]+=sz[v];
		pa[v]=u;
		return true;
	}
}

struct node
{
	int u, v;
	double w;
	int id;
};

bool cmp(node &a, node &b)
{
	return a.w>b.w;
}

bool check(double mid)
{
	vector<node> p;
	for (int i=1; i<=m; i++)
	{
		p.push_back({u[i], v[i], l[i]*mid-c[i], i});
	}
	sort(p.begin(), p.end(), cmp);
	g.clear();
	init();
	double sum=0;
	for (auto x:p)
	{
		if (unite(x.u, x.v))
		{
			sum+=x.w;
			g.push_back(x.id);
		}
	}
	return sum>=0&&(int)g.size()==n-1;
}

signed main()
{
//	freopen("", "r", stdin);
//	freopen("", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i=1; i<=m; i++)
	{
		cin >> u[i] >> v[i] >> l[i] >> c[i];
	}
	double l=0, r=1e9, mid, ans;
	for (int i=1; i<=100; i++)
	{
		mid=(l+r)/2;
		if (check(mid))
		{
			ans=mid;
			// cout<<ans<<endl;
			r=mid;
		} else l=mid;
	}
	// cout<<ans<<endl;
	sort(g.begin(), g.end());
	for (auto x:g) cout<<x<<" ";
}


