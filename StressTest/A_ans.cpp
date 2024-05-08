#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, a[100005];

signed main()
{
	freopen("A.inp", "r", stdin);
	freopen("A.ans", "w", stdout);
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i=1; i<=n; i++) cin >> a[i];
	cout<<a[n];
}

