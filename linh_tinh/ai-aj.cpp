#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1005, mod=2004010501;

int m, n, k;
char a[maxn][maxn];
int f[maxn][maxn];
int dx[]={0,1};
int dy[]={1,0};

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> m >> n >> k;
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++) cin >> a[i][j];
    }
    f[0][0]=1;
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            if (a[(i+i)%m][(j+j)%n]=='#') f[i][j]=0;
            if (!f[i][j]) continue;
            for (int t=0; t<2; t++)
            {
                int nx=i+dx[t], ny=dy[t]+j;
                if (a[(nx+i)%m][(ny+j)%n]=='#') continue;
                f[nx][ny]+=f[i][j];
                f[nx][ny]%=mod;
            }
        }
    }
    cout<<f[m-1][n-1];
}
