#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+7;

int n, a[maxn], b[maxn];

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i=1; i<=n; i++) cin >> a[i] >> b[i];
	sort(a+1, a+n+1);
	sort(b+1, b+n+1);
	int s1=0, ans1=0;
	for (int i=1; i<=n; i++)
	{
		ans1+=(a[i]*(i-1))-s1;
		s1+=a[i];
	}
	int s2=0, ans2=0;
	for (int i=1; i<=n; i++)
	{
		ans2+=b[i]*(i-1)-s2;
		s2+=b[i];
	}
	cout<<ans1+ans2;
}

