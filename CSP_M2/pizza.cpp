#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e7;

int t, n, k;
int p[maxn];

void sieve()
{
	for (int i=2; i*i<=maxn; i++) 
	{
		if (p[i]==0)
		{
			for (int j=i*i; j<=maxn; j+=i)
			{
				if (p[j]==0)
				p[j]=i;
			}
		}
	}
	for (int i=2; i<=maxn; i++)
	{
		if (p[i]==0) p[i]=i;
	}
}

void solve()
{
	cin >> n >> k;
	int g=__gcd(n, k);
	int bcnn=n*k/g;
	map<int, int> mp;
	int tmp=bcnn*k, ans=bcnn;
	while (tmp!=1)
	{
		mp[p[tmp]]++;
		tmp/=p[tmp];
	}
	for (auto x:mp)
	{
		if (x.second&1) ans*=x.first;
	}
	cout<<ans<<endl;
}

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("PIZZA.INP", "r", stdin);
//	freopen("PIZZA.OUT", "w", stdout);
	sieve();
	cin >> t;
	while (t--) solve();
}

