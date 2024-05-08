#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define pii pair <int, int>
const int maxn = 1e5+7, mod=1e9+7;
int n, f[maxn], k, a[maxn], mx=INT_MIN, t;
signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--)
	{
	mx=-maxn;
	cin >> n >> k;
	for (int i=1; i<=n; i++) cin >> a[i], f[i]=0;
	for (int i=n; i>=1; i--)
	{
		if (i+k<=n) f[i]+=f[i+k];
		f[i]+=a[i];
		mx=max(mx, f[i]);
	}
	cout<<mx<<endl;
	}
	
}
