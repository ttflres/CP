#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 7;
int f[maxn], a[maxn];
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	int a[n];
	for (int i=1; i<n; i++) cin >> a[i];
	f[1]=0;
	f[2]=a[1];
	f[3]=a[2]+a[3];
	for (int i=4; i<=n; i++)
	{
		f[i]=min(f[i-1]+a[i-1], f[i-2]+a[i-2]);
	}
	cout<<f[n];
}
