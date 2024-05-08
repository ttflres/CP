#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, x, y, m;

namespace sub1
{
	const int maxn=1e5+7;
	int a[maxn];
	
	void solve()
	{
		a[1]=x;
		for (int i=2; i<=n; i++)
		{
			a[i]=(a[i-1]*x+y)%m;
		}
		sort(a+1, a+n+1);
		int s=0;
		for (int i=1; i<=n; i++) s=(s+a[i]*i)%m;
		cout<<s;
	}
	
}

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("smod.inp", "r", stdin);
	freopen("smod.out", "w", stdout);
	cin >> n >> x >> y >> m;
	if (n<=100000) sub1::solve();
}

