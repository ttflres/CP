#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=2007;
const int inf=1e18;

int n, m;
int a[maxn];

signed main()
{
	freopen("kimtuthap.inp", "r", stdin);
	freopen("kimtuthap.out", "w", stdout);
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i=1; i<=n; i++)
	{
		int s=0;
		bool flag=true;
		for (int j=1; j<=m; j++)
		{
			int x; cin >> x;
			s+=x;
			if (x!=0) flag=false;
		}
		if (flag) a[i]=-inf;
		else a[i]=s;
	}
//	for (int i=1; i<=n; i++) cout<<a[i]<<" ";
	int ans=0, s=0;
	for (int i=1; i<=n; i++)
	{
		if (a[i]!=-inf)
		{
			s+=a[i];
			ans=max(ans, s);
		}
		else
		{
			s=0;
		}
	}
	cout<<ans;
}

