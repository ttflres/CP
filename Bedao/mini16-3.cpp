#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define pii pair <int, int>
const int maxn = 1e5+7, mod=1e9+7;
int a[maxn], b[21], n, k, cnt;
void pro()
{
	string s;
	for (int i=1; i<=n; i++)
	{
		if (b[i]==1) s+=to_string(a[i]);
	}
	if (s.size()==k&&(s[s.size()-1]%2==0)&&(s[0]!='0')) cnt++;
}
void sinh(int i)
{
	for (int j=0; j<2; j++)
	{
		b[i]=j;
		if (i==n) pro();
		else sinh(i+1);
	}
}
signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i=1; i<=n; i++) cin >> a[i];
	cin >> k;
	sinh(1);
	cout<<cnt;
}
