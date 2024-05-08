#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+7;

int n, x[maxn], y[maxn], u[maxn], v[maxn];

namespace sub1
{
	int d[1000][1000];
	int xmin=0, xmax=0, ymin=0, ymax=0;
	void solve()
	{
		for (int i=1; i<=n; i++)
		{
			cin >> x[i] >> y[i] >> u[i] >> v[i];
			xmin=min({x[i], xmin, u[i]});
			xmax=max({xmax, u[i], x[i]});
			ymin=min({ymin, y[i], v[i]});
			ymax=max({ymax, y[i], v[i]});
			for (int j=x[i]; j<=u[i]; j++)
			{
				for (int z=y[i]; z<=v[i]; z++)
				{
					d[j][z]++;
				}
			}
		}
//		cout<<xmin<<" "<<xmax<<" "<<ymin<<" "<<ymax;
		int cnt=0;
		for (int i=xmin; i<=xmax; i++)
		{
			for (int j=ymin; j<=ymax; j++)
			{
				if (d[i][j]&1) cnt++;
			}
		}
		cout<<cnt;
	}
}

namespace sub2
{
	int diff[1005][1005];
	int pf[1005][1005];
	int xmin=0, xmax=0, ymin=0, ymax=0;
	void solve()
	{
		for (int i=1; i<=n; i++)
		{
			cin >> x[i] >> y[i] >> u[i] >> v[i];
			x[i]++, y[i]++, u[i]++, v[i]++;
			xmin=min({x[i], xmin, u[i]});
			xmax=max({xmax, u[i], x[i]});
			ymin=min({ymin, y[i], v[i]});
			ymax=max({ymax, y[i], v[i]});
			diff[x[i]][y[i]]++;
			diff[u[i]+1][v[i]+1]++;
			diff[x[i]][v[i]+1]--;
			diff[u[i]+1][y[i]]--;
		}
		int cnt=0;
		for (int i=1; i<=1001; i++)
		{
			for (int j=1; j<=1001; j++)
			{
				pf[i][j]=pf[i-1][j]+pf[i][j-1]-pf[i-1][j-1]+diff[i][j];
				if (pf[i][j]&1) cnt++;
			}
		}
		cout<<cnt<<endl;
	}
}

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("ODDRECT.INP", "r", stdin);
//	freopen("ODDRECT.OUT", "w", stdout);
	cin >> n;
//	if (n<=100) sub1::solve();
	sub2::solve();
}

