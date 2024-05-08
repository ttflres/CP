#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+7;

int b[21], ans=0;
int a[maxn], n;

void in()
{
	int s=0;
	for (int i=1; i<=n; i++)
	{
		if (b[i]==1) s+=a[i];
	}
	ans=max(ans, s);
	// cout<<ans<<endl;
}
void sinh(int i)
{
	for (int j=0; j<=1; j++)
	{
		b[i]=j;
		if (i==n) in();
		else sinh(i+1);
	}
}


signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i=1; i<=n; i++) cin >> a[i];
	sinh(1);
	cout<<ans;
}
