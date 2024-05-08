#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+7;

int n;
int a[maxn];

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i=1; i<=n; i++) cin >> a[i];
	sort(a+1, a+n+1, greater<int>());
	int mx=a[1], res=0;
	for (int i=1; i<=n; i++)
	{
		if (mx>a[i]) 
		{
			res=a[i];
			break;	
		}
	}
	cout<<res%mx;
	
}

