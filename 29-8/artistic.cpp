#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=3e5+7;

int n, m, q;
string s;
int x[maxn], y[maxn];
int a[maxn], ans=0;

void in()
{
	bool flag=true;
	for (int i=0; i<n; i++)
	{
		cout<<a[i];
	}
	if (flag) ans++;
}

void sinh(int i)
{
	for (int j=0; j<=1; j++)
	{
		if (s[i]!='1') a[i]=j;
		if (i==n-1) in();
		else sinh(i+1); 
	}
}

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("ARTISTIC.INP", "r", stdin);
	freopen("ARTISTIC.OUT", "w", stdout);
	cin >> n >> m >> q;
	cin >> s;
	for (int i=1; i<=q; i++)
	{
		cin >> x[i] >> y[i];
	}
	sinh(0);
	cout<<ans;
}

