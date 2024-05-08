#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1005;
const int dx[]={0,0,-1,1};
const int dy[]={1,-1,0,0};

int n, m, k;
int pp, qq;
queue<pair<pair<int, int>, int>> q;
vector<pair<int, int>> t[maxn][maxn], g[maxn*maxn];
int d[maxn][maxn][4], esc[maxn][maxn], l[maxn][maxn];

void bfs()
{
    while (!q.empty())
    {
        int u=q.first.first, v=q.first.second, w=q.second;
        q.pop();
        if (esc[u][v])
        {
            cout<<d[u][v][w]<<endl;
            exit(0);
        }
        for (int i=0; i<4; i++)
        {
            int nx=u+dx[i], ny=v+dy[i];
            if (nx<1||nx>n||ny<1||ny>m) continue;
            if (a[nx][ny]&&d[nx][ny][w]>d[u][v][w]+1)
            {
                d[nx][ny][w]=d[u][v][w]+1;
                q.push({nx, ny}, w);
            }
        }
        if (w<k)
        {
            for (auto x:t[u][v])
            {
                if (d[u][v][w]<d[x.first][y.second][w+1])
                {
                    d[x.first][y.second][w+1]=d[u][v][w];
                    q.push({x.first, x.second}, w+1);
                }
            }
        }
    }
}

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   cin >> n >> m >> k;
   for (int i=1; i<=n; i++)
   {
       for (int j=1; j<=m; j++)
       {
           cin >> a[i][j];
           g[a[i][j]].push({i, j});
       }
   }
   cin >> pp >> qq;
   for (int i=1; i<=pp; i++)
   {
       int u, v; cin >> u >> v;
       if (a[u][v])
       {
           d[u][v][0]=0;
           q.push({u, v}, 0);
       }
   }
   for (int i=1; i<=qq; i++)
   {
       int u, v; cin >> u >> v;
       esc[u][v]=1;
   }
   for (int i=1; i<=n; i++)
   {
       for (int j=1; j<=m; j++)
       {
           for (auto x:g[i*j])
           {
               if (a[i][j]) t[x.first][x.second].push_back({i, j});
           }
       }
   }
   bfs();

}
