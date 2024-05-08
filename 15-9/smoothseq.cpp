#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+7;

int n, k, a[maxn], dp[maxn];

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	for (int i=1; i<=n; i++) cin >> a[i];
	int l=0, r=2e9;
	while (l<r)
	{
		int mid=(l+r)/2;
		bool flag=0;
		for (int i=1; i<=n; i++)
		{
			dp[i]=i-1;
			for (int j=i-1; j; j--)
			{
				if (a[i]-a[j]<=mid*(i-j))
				{
					dp[i]=min(dp[i], dp[j]+i-j-1);
				}
				if (dp[i]+n-i<=k) flag=1;
			}
		}
		if (flag) r=mid;
		else l=mid+1;
	}
	cout<<r;
}

