#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define pii pair <int, int>
const int maxn = 1e5+7, mod=1e9+7;
ll n, a[maxn], i=2, cnt;
bool check(ll a)
{
	ll tmp=sqrt(a);
	return tmp*tmp==a;
}
signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i=1; i<=n; i++) cin >> a[i];
	while (i<=n)
	{
		if (!check(a[i]*a[i-1]/__gcd(a[i], a[i-1])))
		{
			cnt++;
			i+=2;
		} else i++;
	}
	cout<<cnt;
}
