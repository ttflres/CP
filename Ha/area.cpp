#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=5e4+7;

struct rc
{
	int x, y, t;
	bool operator < (const rc &other) const
	{
		return x<other.x;
	}
};

int n;
vector<rc> r;
multiset<int> st;

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i=1; i<=n; i++)
	{
		int a, b, h; cin >> a >> b >> h;
		r.push_back({a, h, 1});
		r.push_back({b, h, -1});
	}
	sort(r.begin(), r.end());
	st.insert(r[0].y); st.insert(0);
	int pos=r[0].x, ans=0;
	for (int i=1; i<r.size(); i++)
	{
		if (r[i].t==1)
		{
			ans+=(r[i].x-pos)*(*st.rbegin());
			pos=r[i].x;
			st.insert(r[i].y);
		}
		else
		{
			ans+=(r[i].x-pos)*(*st.rbegin());
			pos=r[i].x;
			st.erase(st.find(r[i].y));
		}
	}
	cout<<ans;
}

