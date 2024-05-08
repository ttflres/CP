#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e6+7;

int prime[maxn];
int t, a, b;

void sieve()
{
	for (int i=2; i*i<=maxn; i++)
	{
		if (prime[i]==0)
		{
			for (int j=i*i; j<=maxn; j+=i)
			{
				prime[j]=i;
			}
		}
	}
	for (int i=2; i<=maxn; i++) if (prime[i]==0) prime[i]=i;
}

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	if (fopen("DNUM.INP", "r"))
	{
		freopen("DNUM.INP", "r", stdin);
		freopen("DNUM.OUT", "w", stdout);
	}
	sieve();
	cin >> t;
	while (t--)
	{
		int a, b; cin >> a >> b;
		int g=__gcd(a, b);
		a/=g, b/=g;
		map<int, int> pa, pb;
		while (a!=1)
		{
			pa[prime[a]]++;
			a/=prime[a];
		}
		while (b!=1)
		{
			pb[prime[b]]++;
			b/=prime[b];
		}
		int cnt=0;
		for (auto x:pa) cnt+=x.second;
		for (auto x:pb) cnt+=x.second;
		cout<<cnt<<endl;
	}
}

