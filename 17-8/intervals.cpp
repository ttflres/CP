#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+7;

int n, b[maxn], c[maxn];

signed main()
{
	freopen("INTERVALS.INP", "r", stdin);
	freopen("INTERVALS.OUT", "w", stdout);
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i=1; i<=n; i++){
		int x, y; cin >> x >> y;
		b[i]=x, c[i]=y;
	}
	sort(b+1, b+n+1); sort(c+1, c+n+1);
	int cnt=0;
	for (int i=1; i<=n; i++)
	{
		auto it=upper_bound(b+1, b+n+1, c[i])-b;
		cnt+=(n-it+1);
	}
	cout<<n*(n-1)/2-cnt;
}

