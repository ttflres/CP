#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+7;

int n, q;

string s[maxn];

signed main()
{
 	freopen("marisachain.inp", "r", stdin);
 	freopen("marisachain.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> q;
	for (int i=1; i<=n; i++) cin >> s[i];
	for (int i=1; i<=q; i++)
	{
		string a, b;
		cin >> a >> b;
		int t1=a.size(), t2=b.size();
		int cnt=0;
		for (int i=1; i<=n; i++)
		{
			int tt=s[i].size();
			string c=s[i];
			if (a==c.substr(0, t1)&&b==c.substr(tt-t2, tt)) cnt++;
//			cout<<c.substr(0, t1)<<" "<<c.substr(tt-t2, tt)<<endl;	
		}
		cout<<cnt<<endl;
	
	}
}

