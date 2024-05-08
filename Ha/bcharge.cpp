#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=250004;

int n, a[maxn], pf[maxn], q;
int pfs;
int b[maxn];
//int pos[maxn], d[maxn];

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i=1; i<=n; i++)
	{
		cin >> a[i];
//		b[i]={a[i], i};	
		b[i]=a[i];
	}
	sort(b+1, b+n+1);
	for (int i=1; i<=n; i++)
	{
		pf[i]=pf[i-1]+b[i];
		pfs+=b[i]*i;
//		d[i]=b[i].first;
//		pos[b[i].second]=i;
	}
	cin >> q;
	for (int i=1; i<=q; i++)
	{
		int j, v; cin >> j >> v;
		auto it=upper_bound(b+1, b+n+1, v)-b;
		auto itt=lower_bound(b+1, b+n+1, a[j])-b-1;
		if (a[j]==v) cout<<pfs<<endl;
		else if (a[j]>v)
		{
			cout<<pfs+v*it-a[j]*(itt+1)+pf[itt]-pf[it-1]<<endl;
		}
		else
		{
			cout<<pfs+v*(it-1)-a[j]*(itt+1)-(pf[it-1]-pf[itt+1])<<endl;
		}
	}
	
}

