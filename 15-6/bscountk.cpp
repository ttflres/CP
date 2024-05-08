#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define pii pair <int, int>
const int maxn = 1e6+7;
int n, k, a[maxn], cnt;
signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	for (int i=1; i<=n; i++) cin >> a[i];
	sort(a+1,a+n+1);
	for (int i=1; i<=n; i++)
	{
		int tmp=k-a[i];
		auto it=upper_bound(a+1,a+n+1, tmp)-a-1-i;
		if (it>0) cnt+=it;
	}
	cout<<cnt;
}
