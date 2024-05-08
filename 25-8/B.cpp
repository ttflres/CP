#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e6+5;

int p[maxn];
int t, n, k;

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

int pa[maxn], pb[maxn];

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	sieve();
	cin >> t;
	while (t--)
	{
		memset(pa, 0, sizeof(pa));
		memset(pb, 0, sizeof(pb));
		cin >> n >> k;
		for (int i=2; i<=n; i++)
		{
			int x=i;
			while (x!=1)
			{
				pa[p[x]]++;
				x/=p[x];
			}
		}
		while (k!=1)
		{
			pb[p[k]]++;
			k/=p[k];
		}
//		bool flag=true;
		int ans=maxn;
		for (int i=1; i<=maxn; i++)
		{
			if (pb[i]!=0)
			ans=min(ans, pa[i]/pb[i]);
		}
//		if (flag) cout<<ans<<endl;
		cout<<ans<<endl;
	}
}

