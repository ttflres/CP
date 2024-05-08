#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+7;

int t, n, k;
int a[maxn];

int get(multiset<int>&st)
{
	auto it1=--st.end();
	int mx1=*it1;
	auto it2=--it1;
	int mx2=*it2;
	return mx1+mx2;
}

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		if (n==1) cout<<0<<endl;
		else
		{
		for (int i=1; i<=n; i++) cin >> a[i];
		int l=1, r=1, ans=0;
		multiset<int> st;
		while (r<=n)
		{
			st.insert(a[r]);
//			cout<<get(st)<<endl;
			while (st.size()>=2&&get(st)>k)
			{
				st.erase(st.find(a[l]));
				l++;
			}
			ans=max(ans, r-l+1);
			r++;
		}
		cout<<ans<<endl;
		}
	}
}

