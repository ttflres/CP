#include<bits/stdc++.h>
using namespace std;
#define int long long

int t, n;

signed main()
{
	freopen("GOAT.INP", "r", stdin);
	freopen("GOAT.OUT", "w", stdout);
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--)
	{
		cin >> n;
		if (n%10==0) cout<<"BOBO"<<endl;
		else cout<<"SIUU"<<endl;
	}
}

