#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+7;

int n, x;

namespace sub1
{
	vector<int> v;
	
	void solve()
	{
		int cnt=0;
		while (n--)
		{
			char a; int k;
			cin >> a >> k;
			if (a=='I') 
			{
				v.push_back(k);	
			}
			if (a=='S')
			{
				for (int i=0; i<v.size(); i++)
				{
					v[i]-=k;
				}
				for (int i=0; i<v.size(); i++)
				{
					if (v[i]<x)
					{
						v[i]=-1;
						cnt++;
					}
				}
//				for (auto x:v) cout<<x<<" ";
//				cout<<endl;
			}
			if (a=='A')
			{
				for (int i=0; i<v.size(); i++)
				{
					if (v[i]!=-1)
					v[i]+=k;
				}
			}
			if (a=='F')
			{
				sort(v.begin(), v.end(), greater<int>());
				v.erase(unique(v.begin(), v.end()), v.end());
//				for (int i=0; i<v.size(); i++) if (v[i]<x) v[i]=-1, cnt++;
				if (v.size()<k) cout<<-1<<endl;
				else cout<<v[k-1]<<endl;
			}
		}
			for (auto e:v) if (e<x&&e!=-1) cnt++;
			cout<<cnt<<endl;
	}
}

namespace sub3
{
	multiset<int> st;
	
	void solve()
	{
		int cnt=0;
		while (n--)
		{
			char a; int k;
			cin >> a >> k;
			if (a=='I')
			{
				if (k<x) cnt++;
				if (k>=x) st.insert(k);
			}
			if (a=='F')
			{
				if (k>st.size()) cout<<-1<<endl;
				else
				{
					int d=0;
					for (auto x:st)
					{
						if (d==k) 
						{
							cout<<x<<endl;
							break;	
						}
						d++;
					}
				}
			}
		}
		cout<<cnt<<endl;
	}
}

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("CASHIER.INP", "r", stdin);
	freopen("CASHIER.OUT", "w", stdout);
	cin >> n >> x;
	if (n<=1000) sub1::solve();
	else sub3::solve();
}

