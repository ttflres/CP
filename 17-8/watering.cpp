#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+7;

int n;
stack<int> st;
vector<int>v;
int cnt=0;

signed main()
{
	freopen("WATERING.INP", "r", stdin);
	freopen("WATERING.OUT", "w", stdout);
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	v.push_back(-1e18);
	for (int i=0; i<n; i++)
	{
		int x; cin >> x;
		if (!i) v.push_back(x);
		else if (x==v[i-1]) continue;
		else v.push_back(x);
	}
	v.push_back(-1e18);
	for (int i=0; i<v.size(); i++)
	{
		if (v[i-1]<v[i]&&v[i]>v[i+1]) cnt++;
	}
	cout<<cnt;
}

