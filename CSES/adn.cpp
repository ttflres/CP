#include<bits/stdc++.h>
using namespace std;
#define int long long

string n;
int cnt=1, mx=1;

signed main()
{
//	freopen("", "r", stdin);
//	freopen("", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i=1; i<n.size(); i++)
	{
		if (n[i]==n[i-1])
		{
			cnt++;
			mx=max(mx, cnt);
		}
		else
		{
//			mx=max(mx, cnt);
			cnt=1;
		}
	}
	cout<<mx;
}

