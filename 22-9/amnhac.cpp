#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, k;
string s;
map<char, int> mp;

signed main()
{
	freopen("amnhac.inp", "r", stdin);
	freopen("amnhac.out", "w", stdout);
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	cin >> s;
	for (int i=0; i<s.size(); i++) mp[s[i]]++;
	for (auto x:mp) mp[x.first]*=k;
	if (n==1) 
	{
		cout<<mp[s[0]];
		return 0;
	}
	int ans=0;
	for (int i=1; i<s.size(); i++)
	{
		if (s[i]!=s[i-1]) ans=max(ans, mp[s[i]]+mp[s[i-1]]);
		else ans=max(ans, mp[s[i]]); 
	}
	if (k>1)
	{
		if (s[n-1]!=s[0]) ans=max(ans, mp[s[0]]+mp[s[n-1]]);
	}
	cout<<ans;
}

