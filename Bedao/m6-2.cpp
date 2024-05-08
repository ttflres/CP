#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+7;
int n, m, k;
int a[maxn], pf[maxn], ans=-maxn;
signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> m >> n >> k;
	for (int i=1; i<=m; i++) cin >> a[i];
		sort(a+1,a+m+1);
	for (int i=1; i<=m; i++) pf[i]=pf[i-1]+a[i];
	for (int i=n; i<=m; i++)
		{
			if (a[i]-a[i-n+1]<=k) ans=max(ans, pf[i]-pf[i-n]);
		}
	if (ans==-maxn) cout<<-2;
	else cout<<ans;
}
