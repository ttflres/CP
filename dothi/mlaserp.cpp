#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=111;

int n, m;
char a[maxn][maxn];
int d[maxn][maxn];
int cnt=0;
int sx, sy, ex, ey;

const int dx[]={0, 0, -1, 1};
const int dy[]={1, -1, 0, 0};

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   cin >> n >> m;
   for (int i=1; i<=n; i++)
   {
       string s; cin >> s;
       s=' '+s;
       for (int j=1; j<=m; j++)
       {
           a[i][j]=s[j];
           if (cnt==0&&a[i][j]=='C')
           {
               cnt++;
               sx=i, sy=j;
           }
           else if (a[i][j]=='C'&&cnt)
           {
               ex=i, ey=j;
           }
       }
   }

   queue<pair<int, int>> q;
   memset(d, 0x3f, sizeof(d));
   q.push({sx, sy});
   while (!q.empty())
   {
       int x=q.front().first, y=q.front().second;
       q.pop();
       for (int i=0; i<4; i++)
       {
           int nx=x+dx[i], ny=y+dy[i];
           while (1<=nx&&nx<=n&&1<=ny&&ny<=m&&a[nx][ny]!='*')
           {
               if(d[nx][ny] > d[x][y] + 1)
				{
					d[nx][ny] = d[x][y] + 1;
					if(nx == ex && ny == ey)
					{
						cout << d[nx][ny];
						return 0;
					}
					q.push({nx, ny});
				}
				nx += dx[i];
				ny += dy[i];
           }
       }
   }
   cout<<d[ex][ey]<<endl;
}
