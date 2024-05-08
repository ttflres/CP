#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=200;

int t, n, m;
char a[maxn][maxn];
queue<pair<int, int>> q;
int d[maxn][maxn], l[maxn][maxn];
const int dx[]={0, 0, -1, 1};
const int dy[]={1, -1, 0, 0};

void bfs()
{
    while (!q.empty())
    {
        int x=q.front().first, y=q.front().second;
        q.pop();
        for (int i=0; i<4; i++)
        {
            int nx=x+dx[i], ny=y+dy[i];
            if (nx<1||nx>n||ny<1||ny>m) continue;
            if (d[nx][ny]==0&&a[nx][ny]=='0')
            {
                d[nx][ny]=1;
                q.push({nx, ny});
                l[nx][ny]=l[x][y]+1;
            }
        }
    }
    while (!q.empty()) q.pop();
}

void solve()
{
    memset(d, 0, sizeof(d));
    memset(l, 0x3f, sizeof(l));
    cin >> n >> m;
    for (int i=1; i<=n; i++)
    {
        string s; cin >> s;
        for (int j=0; j<s.size(); j++)
        {
            a[i][j+1]=s[j];
            if (a[i][j+1]=='1')
            {
                q.push({i, j+1});
                l[i][j+1]=0;
                d[i][j+1]=0;
            }
        }
    }
    bfs();
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            cout<<l[i][j]<<" ";
        }
        cout<<endl;
    }

}

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   cin >> t;
   while (t--) solve();

}
