#include<bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O2")
#pragma GCC optimization ("unroll-loops")
#define int long long
const int maxn = 1e5 + 7;
int a[maxn], b[maxn], c[maxn], d[maxn];
int l, n;
int ans=0;
vector<int> mp(maxn,0);
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> l;
	for (int i=0; i<n; i++) cin >> a[i];
	for (int i=0; i<n; i++) cin >> b[i];
	for (int i=0; i<n; i++) cin >> c[i];
	for (int i=0; i<n; i++) cin >> d[i];
	for (int i=0; i<n; i++)
	{
		for (int j=0; j<n; j++)
		{
			mp[a[i]+b[j]]++;
		}
		for (int j=0; j<n; j++)
		{
			int vl=c[i]+d[j];
			if (vl<l) ans+=mp[l-c[i]-d[j]];
		}
	}
	
	cout<<ans;
	
}

