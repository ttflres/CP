#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=505;

int m, n, s, t;
int a[maxn][maxn];
queue<pair<int, int>> q;
int d[maxn][maxn], l[maxn][maxn];
int dx[]={0, 0, -1, 1};
int dy[]={1, -1, 0, 0};

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   freopen("THUPHATSONG.INP", "r", stdin);
   freopen("THUPHATSONG.OUT", "w", stdout);
   cin >> m >> n >> s >> t;
   for (int i=1; i<=s; i++)
   {
       int x, y; cin >> x >> y;
       a[x][y]=1;
       q.push({x, y});
       d[x][y]=1;
       l[x][y]=0;
   }
   for (int i=1; i<=t; i++)
   {
       int x, y; cin >> x >> y;
       a[x][y]=2;
   }
   while (!q.empty())
   {
       int u=q.front().first, v=q.front().second;
       q.pop();
       for (int i=0; i<4; i++)
       {
           int nx=u+dx[i], ny=v+dy[i];
           if (nx<1||nx>m||ny<1||ny>n) continue;
           if (d[nx][ny]==0&&a[nx][ny]!=1)
           {
               l[nx][ny]=l[u][v]+1;
               d[nx][ny]=1;
               q.push({nx, ny});
           }
       }
   }
   int mx=0;
   int cnt=0, ans=0x3f;
   for (int i=1; i<=m; i++)
   {
       for (int j=1; j<=n; j++)
       {
           mx=max(mx, l[i][j]);
           q.push({i, j});
           while (!q.empty())
           {
               int u=q.front().first, v=q.front().second;
               q.pop();
               for (int i=0; i<4; i++)
               {
                   int nx=u+dx[i], ny=v+dy[i];
                   if (nx<1||nx>m||ny<1||ny>n) continue;
                   if (d[nx][ny]==0&&a[nx][ny]!=1)
                   {
                       l[nx][ny]=l[u][v]+1;
                       d[nx][ny]=1;
                       q.push({nx, ny});
                   }
               }
           }
           int nmx=0;
           for (int i=1; i<=m; i++)
           {
               for (int j=1; j<=n; j++)
               {
                   nmx=max(nmx, l[i][j]);
               }
               if (nmx<mx)
               {
                   ans=min(ans,min(nmx, mx));
                   cnt++;
               }
           }
       }
   }
   cout<<ans<<" "<<cnt*2;
}
/*
==================================================+
INPUT
--------------------------------------------------|
2 3
2 4
1 1
1 3
2 1
2 3
2 2
1 2
--------------------------------------------------|
==================================================+
OUTPUT                                            |
--------------------------------------------------|
1 4
--------------------------------------------------|
==================================================+
*/