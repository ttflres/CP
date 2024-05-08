#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+7;

int n, a[maxn];

namespace sub1
{
	int cnt=0;
	void solve()
	{
		for (int i=1; i<=n; i++)
		{
			int mn=maxn, mx=0;
			for (int j=i; j<=n; j++)
			{
				mn=min(mn, a[j]); mx=max(mx, a[j]);
//				cout<<mn<<" "<<mx<<endl;
				if (__gcd(mn, mx)==1) cnt++;
			}
		}
		cout<<cnt<<endl;
	}
}

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("COUNT.INP", "r", stdin);
	freopen("COUNT.OUT", "w", stdout);
	cin >> n;
	for (int i=1; i<=n; i++) cin >> a[i];
	sub1::solve();
}

