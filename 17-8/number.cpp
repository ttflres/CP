#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+7;

string s1, s2;

signed main()
{
	freopen("NUMBER.INP", "r", stdin);
	freopen("NUMBER.OUT", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> s1 >> s2;
	if (s1.size()>s2.size())
	cout<<s1.substr(0,__gcd(s1.size(), s2.size()));
	else cout<<s2.substr(0, __gcd(s1.size(), s2.size()));
}

