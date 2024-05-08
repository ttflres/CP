#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int n, q;
char a[1005][1005];
int d[1005][1005], l[1005][1005];
int dx[]={0, 0, 1, -1};
int dy[]={1, -1, 0, 0};

namespace sub1
{
	void bfs(int x, int y)
	{
	    queue<pair<int, int>> q;
	    q.push({x, y});
	    d[x][y]=1;
	    l[x][y]=1;
	    while (!q.empty())
	    {
	        int u=q.front().first, v=q.front().second;
	        q.pop();
	        for (int i=0; i<4; i++)
	        {
	            int nx=u+dx[i], ny=v+dy[i];
	            if (nx<1||nx>n||ny<1||ny>n) continue;
	            if (d[nx][ny]==0&&a[nx][ny]=='0')
	            {
	                d[nx][ny]=1;
	                l[nx][ny]=l[u][v]+1;
	                q.push({nx, ny});
	            }
	        }
	    }
	}	
	
	void solve()
	{
		while (q--)
	   {
	       memset(d, 0, sizeof(d));
	       memset(l, 0, sizeof(l));
	       int t; cin >> t;
	       if (t==1)
	       {
	           int u, v; cin >> u >> v;
	           a[u][v]='1';
	       }
	       else
	       {
	           int u, v, x, y;
	           cin >> u >> v >> x >> y;
	           bfs(u, v);
	           if (l[x][y])
	           cout<<l[x][y]<<endl;
	           else cout<<-1<<endl;
	       }
	   }
	}
}

namespace sub2
{
	int h[10000005], up[20][10000005];
	vector<int> g[10000005];
	
	int id(int x, int y)
	{
		return (x-1)*n+y;
	}
	
	void to_adj()
	{
		for (int i=1; i<=n; i++)
		{
			for (int j=1; j<=n; j++)
			{
				if (a[i][j]=='0')
				for (int t=0; t<4; t++)
				{
					int nx=i+dx[t], ny=j+dy[t];
					if (1<=nx&&nx<=n&&1<=ny&&ny<=n&&a[nx][ny]=='0') g[id(i, j)].push_back(id(nx, ny));
				}
			}
		}
	}
	
	void dfs(int u, int p) {
	    up[0][u] = p;
	    for (int i = 1; i < 20; i++)
	        up[i][u] = up[i - 1][up[i - 1][u]];
	    for (int& v: g[u])
	    if (v != p) {
	        h[v] = h[u] + 1;
	        dfs(v, u);
    }
}

	int lca(int u, int v) {
	    if (h[u]!=h[v])
	    {
	        if (h[u]<h[v]) swap(u, v);
	        int k=h[u]-h[v];
	        for (int j=0; (1<<j)<=k; j++)
	        {
	            if (k>>j&1) u=up[j][u];
	        }
	    }
	    if (u==v) return u;
	    int k=__lg(h[u]);
	    for (int j=k; j>=0; j--)
	    {
	        if (up[j][u]!=up[j][v]) u=up[j][u], v=up[j][v];
	    }
	    return up[0][u];
	}
	
	int len(int u, int v)
	{
		int c=lca(u, v);
		return h[u]+h[v]-2*h[c]+1;
	}
	
	void solve()
	{
		to_adj();
		dfs(1, 0);
		while (q--)
		{
			int t, u, v, x, y;
			cin >> t >> u >> v >> x >> y;
			if (t==2)
			{
				int a=id(u, v), b=id(x, y);
				//cout<<a<<" "<<b<<endl;
				int t=len(a, b);
				if (t!=0)
				cout<<t<<endl;
				else cout<<-1<<endl;
			}
		}
	}
}

namespace sub3
{
	int parent[10000005], sz[10000005];
	int h[10000005], up[20][10000005];
	vector<int> g[10000005];
	int add[1005][1005];
	
	void make_set(int u)
	{
	   parent[u]=u;
	   sz[u]=1;
	}
	 
	int find_set(int u)
	{
	   return (u==parent[u]) ? u :parent[u]=find_set(parent[u]);
	}
	 
	void union_set(int x, int y)
	{
	   x=find_set(x), y=find_set(y);
	   if (x!=y)
	   {
	      if (sz[x]>sz[y]) swap(x,y);
	      parent[y]=x;
	      sz[x]+=sz[y];
	   }
	}
	
	int id(int x, int y)
	{
		return (x-1)*n+y;
	}
	
	void to_adj()
	{
		for (int i=1; i<=n; i++)
		{
			for (int j=1; j<=n; j++)
			{
				if (a[i][j]=='0'&&!add[i][j])
				for (int t=0; t<4; t++)
				{
					int nx=i+dx[t], ny=j+dy[t];
					if (1<=nx&&nx<=n&&1<=ny&&ny<=n&&a[nx][ny]=='0'&&!add[nx][ny]) 
					{
						g[id(i, j)].push_back(id(nx, ny));	
						make_set(id(i, j));
						make_set(id(nx, ny));
					}
				}
			}
		}
	}
	
	struct query1
	{
		int x, y, id;	
	};
	
	struct query2
	{
		int x, y, u, v, id;
	};
	
	void solve()
	{
		vector<query1> del;
		vector<query2> fin;
		for (int i=1; i<=q; i++)
		{
			int t; cin >> t;
			if (t==1)
			{
				int x, y; cin >> x >> y;
				v.push_back({x, y, i});
				add[x][y]=1;
			}
			else
			{
				int x, y, u, v; cin >> x >> y >> u >> v;
				v.push_back({x, y, u, v, i});
			}
		}
		to_adj();
	}
}

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   if (fopen("KPMC.INP", "r"))
   {
   		freopen("KPMC.INP", "r", stdin);
   		freopen("KPMC.OUT", "w", stdout);
   }
   cin >> n >> q;
   for (int i=1; i<=n; i++)
   {
       string s; cin >> s;
       for (int j=0; j<s.size(); j++)
       {
           a[i][j+1]=s[j];
       }
   }
   if (n<=100) sub1::solve();
   else sub2::solve();

}

