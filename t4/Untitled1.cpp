#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
const int maxn = 9e3 + 7;
int n, m, sx, sy;
pii sus;
char a[maxn][maxn];
int d[maxn][maxn], l[maxn][maxn], p[maxn][maxn];
int moveX[]={-1, 1, 0, 0};
int moveY[]={0, 0, -1, 1};
int mx=1e9;
string dr="nswe";
string ans;
void bts(int sx, int sy)
{
    queue<pii>q;
    d[sx][sy]=1;
    q.push({sx,sy});
    p[sx][sy]=-1;
    while (!q.empty())
    {
        int u=q.front().first;
        int v=q.front().second;
        q.pop();
        for (int i=0; i<4; i++)
        {
            int x=u+moveX[i];
            int y=v+moveY[i];
            if (x<1||x>m||y<1||y>n) continue;
            if (d[x][y]==0&&a[x][y]==' ')
            {
                d[x][y]=1;
                l[x][y]=l[u][v]+1;
                q.push({x,y});
                p[x][y]=i;
            }
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> m >> n;
    cin.ignore();
    for (int i=1; i<=m;i++)
    {
        string s;
        getline(cin,s);
        for (int j=0; j<n; j++)
        {
            a[i][j+1]=s[j];
            if (a[i][j+1]=='+')
            {
                sx=i;
                sy=j+1;
            }
        }
    }
    bts(sx, sy);
    for (int i=1; i<=m; i++)
    {
        if (l[i][1]<mx&&d[i][1]!=0)
        {
            mx=l[i][1];
            sus={i,1};
        }
        if (l[i][n]<mx&&d[i][n]!=0)
        {
            mx=l[i][n];
            sus={i,n};
        }
    }
    for (int i=1; i<=n; i++)
    {
        if (l[1][i]<mx&&d[1][i]!=0)
        {
            mx=l[1][i];
            sus={1,i};
        }
        if (l[n][i]<mx&&d[n][i]!=0)
        {
            mx=l[n][i];
            sus={n,i};
        }
    }
    if (mx==0) cout<<"-1";
    else if ((sx==1||sy==1)||sx==n||sy==n) cout<<"0";
    else
    {
    	cout<<mx<<endl;
    	while (p[sus.first][sus.second]!=-1)
            {
                int crr=p[sus.first][sus.second];
                ans+=dr[crr];
                sus.first-=moveX[crr];
                sus.second-=moveY[crr];
            }
    reverse(ans.begin(), ans.end());
    cout<<ans;
	}
    
}


