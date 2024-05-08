#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+7;

int f[maxn][2];
int n, a[maxn], b[maxn], c[maxn], d[maxn];

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	if (fopen("BOUNDARY.INP", "r"))
	{
		freopen("BOUNDARY.INP", "r", stdin);
		freopen("BOUNDARY.OUT", "w", stdout);
	}
	cin >> n;
	for (int i=1; i<=n; i++) cin >> a[i] >> b[i];
	int ans=0;
	f[1][0]=a[1];
	f[1][1]=b[1];
	for (int i=2; i<=n; i++)
	{
		f[i][1]=max(f[i-1][0]+abs(b[i-1]-a[i])+b[i], f[i-1][1]+abs(a[i-1]-a[i])+b[i]);
		f[i][0]=max(f[i-1][0]+abs(b[i]-b[i-1])+a[i], f[i-1][1]+abs(a[i-1]-b[i])+a[i]);
//		cout<<f[i][1]<<" "<<f[i][0]<<endl;
	}
	cout<<max(f[n][0], f[n][1]);
}


