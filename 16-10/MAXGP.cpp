#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+7;
const int mod=1e9+7;

int n, q, a[maxn];

namespace sub1
{
	int b[100], c[100];
	
	void in()
	{
		vector<int> v;
		for (int i=1; i<=n; i++)
		{
			if (b[i]) v.push_back(a[i]);
		}
		bool flag=true;
		for (int i=1; i<v.size(); i++)
		{
			if (v[i]!=v[i-1]*q) flag=false;
		}
		if (flag)
		{
			c[(int)v.size()]++;
			c[(int)v.size()]%=mod;
//			for (auto x:v) cout<<x<<" ";
//			cout<<endl;
		}
	}
	
	void sinh(int i)
	{
		for (int j=0; j<=1; j++)
		{
			b[i]=j;
			if (i==n) in();
			else sinh(i+1);
		}
	}
	
	void solve()
	{
		sinh(1);
		for (int i=2; i<=n; i++) cout<<c[i]<<" ";
	}
}

namespace sub2
{
	int f[1005][1005];
	void solve()
	{
		for (int t=2; t<=n; t++)
		{
			for (int i=1; i<=n; i++)
			{
				for (int j=i+1; j<=n; j++)
				{
					if (a[j]==a[i]*q)
					{
						if (t==2) f[j][t]=f[i][t-1]+1;
						else
						{
							if (f[i][t-1]) f[j][t]++;
						}
						f[j][t]%=mod;
					}
				}
			}
		}
		for (int t=2; t<=n; t++)
		{
			int s=0;
			for (int i=1; i<=n; i++) s=(s+f[i][t])%mod;
			cout<<s<<" ";
		}
	}
}


signed main()
{
	freopen("MAXGP.INP", "r", stdin);
	freopen("MAXGP.OUT", "w", stdout);
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> q;
	for (int i=1; i<=n; i++) cin >> a[i];
	if (n<=20) sub1::solve();
	else sub2::solve();
}

