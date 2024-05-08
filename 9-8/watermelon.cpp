#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+7;

int n, k;
int a[maxn], b[maxn];

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("watermelon.inp", "r", stdin);
	freopen("watermelon.out", "w", stdout);
	cin >> n >> k;
	for (int i=1; i<=n; i++) cin >> a[i];
	for (int i=1; i<=n; i++) cin >> b[i];
	int mx=0, crr=0;
	for (int i=1; i<=n; i++)
	{
		crr+=a[i];
		if (crr<0) crr=0;
		mx=max(mx, crr);
	}
	cout<<mx;
}

