#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=25005;

struct node
{
	int x, id, type;
	bool operator < (const node &o) const
	{
		return x<o.x;
	}
};

vector<node> v;
int n;
int cnt[maxn];

struct machine
{
	int a, b;
}mc[maxn];

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i=1; i<=n; i++)
	{
		int a, b; cin >> a >> b;
		mc[i].a=a, mc[i].b=b;
		v.push_back({a, 1, i});
		v.push_back({b, 2, i});
	}
	sort(v.begin(), v.end());
	vector<int> Front, Back;
	for (auto x:v)
	{
		if (x.id==1&&cnt[x.type]==0)
		{
			Front.push_back(x.type);
			cnt[x.type]=1;
		}
		if (x.id==2&&cnt[x.type]==0)
		{
			Back.push_back(x.type);
			cnt[x.type]=1;
		}
	}
	vector<int> las;
	reverse(Back.begin(), Back.end());
	for (auto x:Front) las.push_back(x);
	for (auto x:Back) las.push_back(x);
	vector<machine> v;
	for (auto x:las) v.push_back({mc[x].a, mc[x].b});
	int ans=0;
//	for (auto x:v) {
//		cout<<x.a<<" "<<x.b<<endl;
//	}
	int aa=0, an=0, bb=0, bn=0;
	for (int i=0; i<v.size(); i++)
	{
		aa=an;
		an=aa+v[i].a;
		bb=max(bn, an);
		bn=bb+v[i].b;
	}
	cout<<bn<<endl;
	
}

