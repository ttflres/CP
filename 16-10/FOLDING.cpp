#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=50;

int n, q;

signed main()
{
	freopen("FOLDING.INP", "r", stdin);
	freopen("FOLDING.OUT", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> q;
	while (q--)
	{
		string s; cin >> s;
		vector<int> g[5];
		for (int i=0; i<s.size(); i++)
		{
			if (s[i]=='A') g[1].push_back(i);
			else if (s[i]=='T') g[2].push_back(i);
			else if (s[i]=='G') g[3].push_back(i);
			else if (s[i]=='C') g[4].push_back(i);
		}
		int ans=0;
		if (g[1].size()>=2)
		{
			int cnt=0;
			int d[n]={0};
			for (int i=1; i<g[1].size(); i++)
			{
				if ((g[1][i]-g[1][i-1]-1)%2==0)
				{
					cnt++;
					d[g[1][i-1]]=1;
				}
			}
			for (int i=0; i<g[1].size(); i++)
			{
				if (d[g[1][i]]==0)
				{
					for (int j=i+1; j<g[1].size(); j++)
					{
//						cout<<g[1][j]-g[1][i]-1<<endl;
						if ((g[1][j]-g[1][i]-1)%2==0)
						{
							cnt++;
							d[g[1][i]]=1;
						}
					}
				}
			}
//			cout<<1<<" "<<cnt<<endl;
			ans+=cnt;
		}
		if (g[2].size()>=2)
		{
			int cnt=0;
			int d[n]={0};
			for (int i=1; i<g[2].size(); i++)
			{
				if ((g[2][i]-g[2][i-1]-1)%2==0)
				{
					cnt++;
					d[g[1][i-1]]=1;
				}
			}
			for (int i=0; i<g[2].size(); i++)
			{
				if (d[g[2][i]]==0)
				{
					for (int j=i+1; j<g[2].size(); j++)
					{
//						cout<<g[1][j]-g[1][i]-1<<endl;
						if ((g[2][j]-g[2][i]-1)%2==0)
						{
							cnt++;
							d[g[2][i]]=1;
						}
					}
				}
			}
//			cout<<2<<" "<<cnt<<endl;
			ans+=cnt;
		}
		if (g[3].size()>=2)
		{
			int cnt=0;
			int d[n]={0};
			for (int i=1; i<g[3].size(); i++)
			{
				if ((g[3][i]-g[3][i-1]-1)%2==0)
				{
					cnt++;
					d[g[3][i-1]]=1;
				}
			}
			for (int i=0; i<g[3].size(); i++)
			{
				if (d[g[3][i]]==0)
				{
					for (int j=i+1; j<g[3].size(); j++)
					{
//						cout<<g[1][j]-g[1][i]-1<<endl;
						if ((g[3][j]-g[3][i]-1)%2==0)
						{
							cnt++;
							d[g[3][i]]=1;
						}
					}
				}
			}
//			cout<<3<<" "<<cnt<<endl;
			ans+=cnt;
		}
		if (g[4].size()>=2)
		{
			int cnt=0;
			int d[n]={0};
			for (int i=1; i<g[4].size(); i++)
			{
				if ((g[4][i]-g[4][i-1]-1)%2==0)
				{
					cnt++;
					d[g[4][i-1]]=1;
				}
			}
			for (int i=0; i<g[4].size(); i++)
			{
				if (d[g[4][i]]==0)
				{
					for (int j=i+1; j<g[4].size(); j++)
					{
//						cout<<g[1][j]-g[1][i]-1<<endl;
						if ((g[4][j]-g[4][i]-1)%2==0)
						{
							cnt++;
							d[g[4][i]]=1;
						}
					}
				}
			}
//			cout<<4<<" "<<cnt<<endl;
			ans+=cnt;
		}
		cout<<ans<<endl;
	}
	
}
/*
5
3
AGTCG
CTCTC
AAGGA

*/

