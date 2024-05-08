#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, m, k;
char a[4000][4000];

namespace sub12
{
	int pf[4000][4000];
	
	void solve()
	{
		cin >> n >> m >> k;
		for (int i=1; i<=n; i++)
		{
			for (int j=1; j<=m; j++)
			{
				cin >> a[i][j];
			}
		}
		for (int i=1; i<=n; i++)
		{
			for (int j=1; j<=m; j++)
			{
				pf[i][j]=pf[i-1][j]+pf[i][j-1]-pf[i-1][j-1]+(a[i-1][j-1]=='A');
			}
		}
		int ans=0;
		for (int x1=1; x1<=n; x1++)
		{
			for (int y1=1; y1<=m; y1++)
			{
				for (int x2=x1+1; x2<=n; x2++)
				{
					for (int y2=y1+1; y2<=m; y2++)
					{
						int crr=pf[x2][y2]-pf[x1-1][y2]-pf[x2][y1-1]+pf[x1-1][y1-1];
						if (crr<=k) ans=max(ans, (x2-x1)*(y2-y1));
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	
	void bo_cua_solve()
	{
		int t; cin >> t;
		while (t--) solve();
	}
}

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	sub12::bo_cua_solve();
}

