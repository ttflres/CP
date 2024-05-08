#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1005;

int n, m, k;
int a[maxn][maxn];
int dx[]={0, 0, -1, 1};
int dy[]={1, -1, 0, 0};

namespace khong
{
	int l[maxn][maxn];
	struct edge{
		int dis, u, v;
		edge () {};
		edge ( int _dis, int _u, int _v ) : dis(_dis), u(_u), v(_v) {};
	};
	
	class compare{
		public:
			bool operator () ( const edge &a, const edge &b ) {
				return a.dis > b.dis;
			}
	};
	void dijkstra()
	{
		for (int i=1; i<=n; i++)
		{
			for (int j=1; j<=m; j++) l[i][j]=1e18;
		}
		priority_queue<edge, vector<edge>, compare> pq;
		l[1][1]=0;
		pq.push({l[1][1], 1, 1});
		while (!pq.empty())
		{
			int u=pq.top().u, v=pq.top().v;
			pq.pop();
			for (int i=0; i<4; i++)
			{
				int nx=u+dx[i], ny=v+dy[i];
				if (nx>=1&&nx<=n&&1<=ny&&ny<=m&&a[nx][ny]!=-1)
				{
					if (l[nx][ny]>l[u][v]+a[nx][ny])
					{
						l[nx][ny]=l[u][v]+a[nx][ny];
						pq.push({l[nx][ny], nx, ny});
					}
				}
			}
		}
	}
	
	void solve()
	{
		dijkstra();
		cout<<l[n][m];
	}
}

namespace co
{
	int l[maxn][maxn][6];
	struct edge{
		int dis, u, v, w;
		edge () {};
		edge ( int _dis, int _u, int _v, int _w ) : dis(_dis), u(_u), v(_v), w(_w) {};
	};
	
	class compare{
		public:
			bool operator () ( const edge &a, const edge &b ) {
				return a.dis > b.dis;
			}
	};
	
	void dijkstra()
	{
		for (int t=0; t<=5; t++)
		{
			for (int i=1; i<=n; i++)
			{
				for (int j=1; j<=m; j++) l[i][j][t]=1e18;
			}	
		}
		priority_queue<edge, vector<edge>, compare> pq;
		l[1][1][0]=0;
		pq.push({l[1][1][0], 1, 1, 0});
		while (!pq.empty())
		{
			int u=pq.top().u, v=pq.top().v, w=pq.top().w;
			pq.pop();
			for (int i=0; i<4; i++)
			{
				int nx=u+dx[i], ny=v+dy[i];
				if (nx>=1&&nx<=n&&1<=ny&&ny<=m)
				{
					if (l[nx][ny][w]>l[u][v][w]+a[nx][ny]&&a[nx][ny]!=-1)
					{
						l[nx][ny][w]=l[u][v][w]+a[nx][ny];
						pq.push({l[nx][ny][w], nx, ny, w});
					}
					if (w<k&&l[nx][ny][w+1]>l[u][v][w]&&a[nx][ny]==-1)
					{
						l[nx][ny][w+1]=l[u][v][w];
						pq.push({l[nx][ny][w+1], nx, ny, w+1});
					}
				}
			}
		}
	}
	
	void solve()
	{
		dijkstra();
		int ans=1e18;
		for (int t=0; t<=k; t++) ans=min(ans, l[n][m][t]);
		cout<<ans;
	}
}

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("BRUHDERLAND.INP", "r", stdin);
	freopen("BRUHDERLAND.OUT", "w", stdout);
	cin >> n >> m >> k;
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=m; j++)
		{
			char c; cin >> c;
			if (c=='.') a[i][j]=0;
			if (c=='*') a[i][j]=-1;
			if (c=='A')	a[i][j]=1;
			if (c=='B') a[i][j]=2;		
		}
	}
	if (k==0) khong::solve();
	else co::solve();
}

