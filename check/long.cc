#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+7;

int n, m, k, t;
int a[maxn], b[maxn], s1, s2;

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
//	freopen("watching.inp", "r", stdin);
//	freopen("watching.out", "w", stdout);
	cin >> n >> m >> t >> k;
	for (int i=1; i<=n; i++) cin >> a[i];
	for (int i=1; i<=m; i++) cin >> b[i];
	int i=1, j=1, crr=0;
	while (i<=n&&j<=m)
	{
		while (a[i]<crr&&i<=n) i++;
		if (a[i]>t) {s1+=t-a[i]; break;}	
		s1+=a[i]-crr;
		if (a[i]==crr) 
		{
			s1+=k, a[i]+=k;
			if (i+1<=n) crr=a[i+1];
		}
		else crr=a[i];
		if (crr>t) break;
		while (b[j]<crr&&j<=m) j++;
		if (b[j]>t) {s2+=t-b[j]; break;}	
		s2+=b[j]-crr;
		if (b[j]==crr) 
		{
			s2+=k, b[j]+=k;	
			if (j+1<=m) crr=b[j+1];
		}
		else crr=b[j];
//		crr=b[j];
		if (crr>t) break;
//		cout<<s2<<endl;
		j++; i++;
		
	}
	cout<<s1<<" "<<s2;
}
