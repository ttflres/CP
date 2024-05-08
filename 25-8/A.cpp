#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e6+5;

int p[maxn];
int t, n;

void sieve()
{
	for (int i=2; i*i<=maxn; i++)
	{
		if (p[i]==0)
		{
			for (int j=i*i; j<=maxn; j+=i)
			{
				if (p[j]==0) p[j]=i;
			}
		}
	}
	for (int i=2; i<=maxn; i++) if (p[i]==0) p[i]=i;
}

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	sieve();
	cin >> t;
	while (t--)
	{
		cin >> n;
		map<int, int> mp;
		while (n!=1)
		{
			mp[p[n]]++;
			n/=p[n];	
		}
		int ans=1;
		for (auto x:mp)
		{
			if (x.second&1) ans*=x.first;
		}
		cout<<ans<<endl;
	}
}

