#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=2e5+7;

int n, a[maxn];

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i=1; i<=n; i++) cin >> a[i];
	int cnt=0;
	for (int i=2; i<=n; i++)
	{
		if (a[i]<a[i-1])
		{
			cnt+=a[i-1]-a[i];
			a[i]=a[i-1];
		}
	}
	cout<<cnt;
}

