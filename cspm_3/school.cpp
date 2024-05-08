#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

const int maxn = 1e5 + 7;
int n, m, k, X;
vector<pii> g[maxn];
int l[maxn], tr[maxn];

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	if (fopen("SCHOOL.INP", "r"))
	{
	freopen("SCHOOL.INP", "r", stdin);
	freopen("SCHOOL.OUT", "w", stdout);		
	}
	cin >> n >> m >> k >> X;
	for (int i=1; i<=m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		g[a].push_back({c, b});
		g[b].push_back({c, a});
	}
	if (k==1)
	{
		int x; cin >> x;
		int mx=0, crr=0;
		priority_queue<pii, vector<pii>, greater<pii>> pq;
	    for (int i=1; i<=n; i++) l[i]=1e18;
	    l[x]=0;
	    pq.push({0, x});
	    int i,j,c;
	    while (!pq.empty())
	    {
	        i=pq.top().second;
	        c=pq.top().first;
	        pq.pop();
	        if (l[i]!=c) continue;
	        for (auto v:g[i])
	        {
	            j=v.second;
	            c=v.first;
	            if (l[j]>l[i]+c)
	            {
	                l[j]=l[i]+c;
	                pq.push({l[j], j});
	            }
	        }
	    }
		for (int i=1; i<=n; i++)
		{
			if (l[i]<=X)
			{
				crr=max(crr, i);
			}
		}
		cout<<crr<<endl;
	}
	else
	{
		int ans=1e9;
		for (int t=1; t<=k; t++)
		{
			int x; cin >> x;
			int mx=0, crr=0;
			priority_queue<pii, vector<pii>, greater<pii>> pq;
		    for (int i=1; i<=n; i++) l[i]=1e18;
		    l[x]=0;
		    pq.push({0, x});
		    int i,j,c;
		    while (!pq.empty())
		    {
		        i=pq.top().second;
		        c=pq.top().first;
		        pq.pop();
		        if (l[i]!=c) continue;
		        for (auto v:g[i])
		        {
		            j=v.second;
		            c=v.first;
		            if (l[j]>l[i]+c)
		            {
		                l[j]=l[i]+c;
		                pq.push({l[j], j});
		            }
		        }
		    }
			for (int i=1; i<=n; i++)
			{
				if (l[i]<=X)
				{
					crr=max(crr, i);
				}
			}
			ans=min(ans, crr);
		}
		cout<<ans;
	}
}

