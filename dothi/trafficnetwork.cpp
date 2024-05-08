#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=255;

int a[maxn][maxn];
int n, m, sz;
int d[maxn][maxn];

const int dx[]={0, 0, -1, 1};
const int dy[]={1, -1, 0, 0};

void dfs(int x, int y)
{
    d[x][y]=1;
    for (int i=0; i<4; i++)
    {
        int nx=x+dx[i], ny=y+dy[i];
        if (nx>=1&&nx<=n&&ny>=1&&ny<=m&&a[nx][ny]==1&&d[nx][ny]==0)
        {
            sz++;
            dfs(nx, ny);
        }
    }
}

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   while (cin >> n >> m)
   {
       int cnt=0;
       if (n==0&&m==0) return 0;
       memset(d, 0, sizeof(d));
       map<int, int> mp;
      for (int i=1; i<=n; i++)
       {
           for (int j=1; j<=m; j++)
           {
               cin >> a[i][j];
           }
       }
       for (int i=1; i<=n; i++)
       {
           for (int j=1; j<=m; j++)
           {
               if (a[i][j]==1&&!d[i][j])
               {
                   cnt++;
                   sz=1;
                   dfs(i, j);
                   //cout<<sz<<endl;
                   mp[sz]++;
               }
           }
       }
       cout<<cnt<<endl;
       for (auto x:mp) cout<<x.first<<" "<<x.second<<endl;
   }


}
