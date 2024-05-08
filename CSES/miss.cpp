#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;
map<int, int> mp;

signed main()
{
//	freopen("", "r", stdin);
//	freopen("", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i=1; i<n; i++)
	{
		int x; cin >> x;
		mp[x]++;
	}
	for (int i=1; i<=n; i++)
	{
		if (mp[i]==0)
		{
			cout<<i;
			return 0;
		}
	}
}

