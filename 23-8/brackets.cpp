#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+7;

int n, a[maxn], b[2*maxn];

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	if (fopen("BRACKETS.INP", "r"))
	{
		freopen("BRACKETS.INP", "r", stdin);
		freopen("BRACKETS.OUT", "w", stdout);
	}
	cin >> n;
	int crr=1;
	for (int i=1; i<=n; i++) cin >> a[i];
	for (int i=1; i<=n; i++)
	{
		while (b[crr]!=0) crr++;
		b[crr]=1;
		b[crr+a[i]+1]=-1;
	}
	for (int i=1; i<=2*n; i++) 
	{
		if (b[i]==1) cout<<"(";
		else cout<<")";
	}
}

