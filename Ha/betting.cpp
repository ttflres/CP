#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

const int maxn=1e5+7;

int n;
double ans;
double a[maxn], b[maxn];

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i=1; i<=n; i++)
	{
		cin >> a[i] >> b[i];
	}
	sort(a+1, a+n+1, greater<double>());
	sort(b+1, b+n+1, greater<double>());
	for (int i=1; i<=n; i++)
	{
		a[i]+=a[i-1];
		b[i]+=b[i-1];
	}
	for (int i=1; i<=n; i++)
	{
		int p1=lower_bound(b+1, b+n+1, a[i])-b, p2=lower_bound(a+1, a+n+1, b[i])-a;
		if (b[p1]>=a[i]) ans=max(ans, a[i]-i-p1);
		if (a[p2]>=b[i]) ans=max(ans, b[i]-i-p2);
	}
	cout<<setprecision(4)<<fixed<<ans;
}

