#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e6+6;

int n, k, a[maxn];
int pf[maxn];
int ans=0;

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("BOKPHANTU.INP", "r", stdin);
//	freopen("BOKPHANTU.OUT", "w", stdout);
	cin >> n >> k;
	for (int i=1; i<=n; i++)
	{
		cin >> a[i];
		pf[i]=pf[i-1]+a[i];
	}
	for (int i=k; i<=n; i++)
	{
		for (int j=i+k; j<=n; j++)
		{
//			cout<<pf[i]-pf[i-k]<<" "<<pf[j]-pf[j-k]<<endl;
			ans=max(ans, abs((pf[i]-pf[i-k])-(pf[j]-pf[j-k])));
		}
	}
	cout<<ans;
	
}

