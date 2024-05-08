#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define pii pair <int, int>
const int maxn = 1e5+7, mod=1e9+7;
int n, m;
vector<int>a[maxn];
signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			int x; cin >> x;
			a[i].push_back(x);
			a[i][j]=1-a[i][j];
		}
	}
	for (int i=0; i<n; i++)
	{	for (int j=0; j<m; j++)
		{
			cout<<a[i][j]<<' ';
		}
		cout<<endl;
	}
}
