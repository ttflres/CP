#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=200;

int n, a[maxn][11];

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	if (fopen("acm.inp", "r"))
	{
		freopen("acm.inp", "r", stdin);
		freopen("acm.out", "w", stdout);
	}
	cin >> n;
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=11; j++)
		{
			cin >> a[i][j];
		}
	}
	int ans=0;
	for (int i=1; i<=n; i++)
	{
		for (int j=i+1; j<=n; j++)
		{
			for (int t=j+1; t<=n; t++)
			{
				int crr=0;
				for (int z=1; z<=11; z++)
				{
					crr+=max({a[i][z], a[j][z], a[t][z]});
				}	
				ans=max(ans, crr);
			}
		}
	}
	cout<<ans;
}

