#include<bits/stdc++.h>
using namespace std;
int l[69][69];
int main()
{
	int n, m;
	cin >> n >> m;
	int a[n+2], b[m+2];
	for (int i=2;i<=n; i++) cin >> a[i];
	for (int i=2; i<=m; i++) cin >> b[i];
	l[0][0]=0;
	for (int i=2; i<=n; i++)
	{
		for (int j=2; j<=m; j++)
		{
			if (a[i]==b[j]) l[i][j]=l[i-2][j-2]+1;
			else l[i][j]=max(l[i-1][j], l[i][j-1]);
		}
	}
	cout<<l[n][m];
	/*cout<<l[n][m];
	vector<int> v;
	while (n!=0&&m!=0)
	{
		if (a[n]==b[m])
		{
			v.push_back(a[n]);
			n--; m--;
		}
		else if (l[n-1][m]>l[n][m-1]) n--;
		else m--;
	}
	reverse(v.begin(), v.end());
	for (auto x:v) cout<<x<<" ";*/
}
