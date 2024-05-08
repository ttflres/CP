#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=2e5+7;

int n, q;
int a[maxn];
vector<pair<int, int>> v;
vector<int> g[maxn];
int res[maxn], cnt[maxn];

struct ev
{
	int id, x, sign;
};

vector<ev> event[maxn];

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> q;
	for (int i=1; i<=n; i++) 
	{
		cin >> a[i];
		v.push_back({a[i], i});
	}
	sort(v.begin(), v.end());
	for (int i=1; i<=200000; i++)
	{
		for (int j=i; j<=200000; j+=i)
		{
			g[j].push_back(i);
		}
	}
	for (int i=0; i<q; i++)
	{
		int l, r, x; cin >> l >> r >> x;
		for (int j:g[x])
		{
			res[i]+=upper_bound(v.begin(), v.end(), make_pair(j, r))-lower_bound(v.begin(), v.end(), make_pair(j, l));
		}
//		cout<<res[i]<<endl;
		event[l-1].push_back({i, x, -1});
		event[r].push_back({i, x, 1});
	}
	for (int i=1; i<=n; i++)
	{
		cnt[a[i]]++;
		for (auto u:event[i])
		{
			for (int j=2*u.x; j<=200000; j+=u.x)
			{
				res[u.id]+=u.sign*cnt[j];
			}
		}
	}
	for (int i=0; i<q; i++) cout<<res[i]<<" ";
}

