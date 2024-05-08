#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+7;

int n, k, x;

struct event
{
	int i, m, j;
} s[maxn];

int trc(int i, int m, int j, int crr)
{
	if (j<i)
	{
		if (crr>=j&&crr<j+m) return crr+(i-j);
		else if (crr>=j+m&&crr<i+m) return crr-m; 
	}
	if (j>i)
	{
		if (crr>=j&&crr<j+m) return crr-(j-i);
		else if (crr>=i&&crr<j) return crr+m;
	}
	return crr;
}

signed main()
{
//	freopen("", "r", stdin);
//	freopen("", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k >> x;
	for (int i=1; i<=x; i++)
	{
		cin >> s[i].i >> s[i].m >> s[i].j;
	}
	for (int i=1; i<=k; i++)
	{
		int crr=i;
		for (int j=x; j>=1; j--)
		{
			crr=trc(s[j].i, s[j].m, s[j].j, crr);
		}
		cout<<crr<<" ";
	}
}

