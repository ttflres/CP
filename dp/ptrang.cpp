#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 7;
int f[1000];
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	int a[n+1], b[n+1];
	b[0]=0;
	for (int i=1; i<=n; i++)
	{
		f[i]=1e9;
		cin >> a[i];
		b[i]=b[i-1]+a[i];
	}
	for (int i=1; i<=n; i++)
	{
		for (int j=i; j>=1; j--)
		{
			if (b[i]-b[j-1]<=k)
			f[i]=min(f[i], max(f[j-1], k-(b[i]-b[j-1])));
		}
	}
	cout<<f[n];
}



