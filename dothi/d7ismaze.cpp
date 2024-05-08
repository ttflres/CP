#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=3007;

int n;
char a[maxn][maxn];
int vis[maxn][maxn];
int cnt=0;
const int dx[]={0, 0, -1, 1};
const int dy[]={1, -1, 0, 0};
int stx, sty;
int check=0;
int ko=0;

void dfs(int stx, int sty)
{
	vis[stx][sty]=1;
	for (int i=0; i<4; i++)
	{
		int nx=stx+dx[i], ny=sty+dy[i];
		if (1<=nx&&nx<=n&&1<=ny&&ny<=n)
		{
			if (vis[nx][ny]==1) check++;
			else if (vis[nx][ny]==0)
			{
				dfs(nx, ny);
			}
		}
	}
}

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i=1; i<=n; i++)
	{
		for (int j=1; j<=n; j++)
		{
			cin >> a[i][j];
			if (a[i][j]=='1') vis[i][j]=-1, ko++;
			if (cnt==0&&a[i][j]=='0')
			{
				stx=i, sty=j;
				check++;
				cnt++;
			}
		}
	}
	dfs(stx, sty);
	if (check==n*n-ko) cout<<"Yes";
	else cout<<"No";
}

