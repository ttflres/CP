#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1007;

int n, k;
int a[maxn];

namespace thu
{
	int f[maxn][maxn];
	bool ok[maxn][maxn];
	vector<int> lil;
	
	void trace(int i, int j)
	{
		int pos=(a[i]+j)%k, neg=(a[i]-j+k*k)%k;
		if (f[i][pos]!=0)
		{
			trace(i-1, neg);
			lil.push_back(i);
		}
		else if (f[i][neg]!=0)
		{
			trace(i-1, pos);
			lil.push_back(i);
		}
	}
	
	void solve()
	{
		for (int i=1; i<=n; i++)
		{
			for (int j=0; j<k; j++)
			{
				int pos=(j+a[i])%k;
				int neg=(j-a[i]+k*k)%k;
				if (!ok[i][pos])
				{
					ok[i][pos]=true;
					f[i][pos]=1;
				}
				if (!ok[i][neg])
				{
					ok[i][neg]=true;
					f[i][neg]=1;
				}
			}
		}
	trace(n, 0);
	if (lil.size()==0) cout<<0;
	else for (auto x:lil) cout<<x<<" ";
	}
}

namespace sub
{
	int f[maxn];
	vector<vector<int>> ans;
	
	void in()
	{
		vector<int> lil;
		int sum=0;
		for (int i=1; i<=n; i++)
		{
			if (f[i]==1) sum+=a[i], lil.push_back(i);
			if (f[i]==2) sum-=a[i], lil.push_back(-i);
		}
		if (sum%k==0&&sum>=0)
		{
			if (!lil.empty())
			ans.push_back(lil);
			//for (auto x:lil) cout<<x<<" ";
			//cout<<endl;
		}
	}
	
	void sinh(int i)
	{
		for (int j=0; j<3; j++)
		{
			f[i]=j;
			if (i==n)
			{
				in();
			}
			else sinh(i+1);
		}
	}
	
	void solve()
	{
		sinh(1);
		if (ans.empty())
		{
			cout<<0;
			return;
		}
		for (int i=0; i<1; i++)
		{
			for (auto x:ans[i]) cout<<x<<" ";
			return;
		}
		
	}
}

signed main()
{
	freopen("GIFT.INP", "r", stdin);
	freopen("GIFT.OUT", "w", stdout);
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	for (int i=1; i<=n; i++) cin >> a[i];
	for (int i=1; i<=n; i++) a[i]%=k;
	if (n<=100) sub::solve();
	else thu::solve();
	
}

