/*#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=105;

int n, m;
char a[maxn][maxn];
int dis[maxn][maxn][16], vis[maxn][maxn][16];
queue<pair<pair<int, int>, int>> q;
const int dx[]={0, 0, -1, 1};
const int dy[]={1, -1, 0, 0};
int ans=-1;

bool valid(int x, int y)
{
    return (x>=1&&x<=n&&y>=1&&y<=m);
}

bool check_var(char c, int k)
{
    return ((c=='B'&&(k&1))||(c=='Y'&&(k&2))||(c=='R'&&(k&4))||(c=='G'&&(k&8))||(c=='.')||(c=='*')||(c=='b')||(c=='y')||(c=='r')||(c=='g')||c=='X');
}

void bfs()
{
    while (!q.empty()) q.pop();
    while (!q.empty())
    {
        int x=q.front().first.first, y=q.front().first.second, k=q.front().second, nk=q.front().second;
        q.pop();
        if (a[x][y]=='X')
        {
            ans=dis[x][y][k];
            return;
        }
        if (a[x][y] == 'b')
        {
			nk |= 1;
		}
		if (a[x][y] == 'y')
        {
			nk |= 2;
		}
        if (a[x][y] == 'r')
        {
			nk |= 4;
		}
		if (a[x][y] == 'g')
        {
			nk |= 8;
		}
        for (int i=0; i<4; i++)
        {
            int nx=x+dx[i], ny=y+dy[i];
            if (!valid(x, y)) continue;
            if (!vis[nx][ny][nk])
            {
                if (check_var(a[nx][ny], nk))
                {
                    dis[nx][ny][nk]=dis[x][y][k]+1;
                    vis[nx][ny][nk]=1;
                    q.push({{nx, ny}, nk});
                }
            }
        }
    }

}

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   while (cin >> n >> m)
   {
       if (n==m&&n==0) return 0;
       memset(vis, 0, sizeof(vis));
       memset(dis, 0, sizeof(dis));
       for (int i=1; i<=n; i++)
       {
           string s; cin >> s;
           s=' '+s;
           for (int j=1; j<=m; j++)
           {
               a[i][j]=s[j];
               if (a[i][j]=='*') q.push({{i, j}, 0});
           }
       }
       bfs();
       if (ans!=-1) cout << "Escape possible in " << ans << " steps." << endl;
       else cout << "The poor student is trapped!" << endl;
   }

}*/
#include <cstdio>
#include <queue>
#include <cctype>
using namespace std;

typedef pair< int, int > pii;
typedef pair< pii, int > ppi;
const int MAX = 101;
char grid[MAX][MAX];
int d[MAX][MAX][16], R, C;
int dr[4] = {0, 0, 1,-1};
int dc[4] = {1,-1, 0, 0};

inline bool ingrid(const pii &p) {
	return (p.first>=0 && p.first<R && p.second>=0 && p.second<C);
};

int bfs(const pii &s) {
	pii u, v;
	int umask, vmask, i;
	queue< ppi > Q;
	Q.push(ppi(s,0));
	d[s.first][s.second][0] = 0;
	while(!Q.empty()) {
		u = Q.front().first;
		umask = Q.front().second;
		Q.pop();
		for(i=0; i<4; i++) {
			v = pii(u.first+dr[i], u.second+dc[i]);
			if(ingrid(v) && grid[v.first][v.second]!='#') {
				if(grid[v.first][v.second]=='X') return d[u.first][u.second][umask]+1;
				if(d[v.first][v.second][umask]==-1) {
					vmask = umask;
					if(islower(grid[v.first][v.second])) {
						switch(grid[v.first][v.second]) {
							case 'b': vmask |= 0x1; break;
							case 'y': vmask |= 0x2; break;
							case 'r': vmask |= 0x4; break;
							case 'g': vmask |= 0x8; break;
						}
						Q.push(ppi(v, vmask));
						d[v.first][v.second][umask] = d[u.first][u.second][umask]+1;
						d[v.first][v.second][vmask] = d[v.first][v.second][umask];
					}
					else if(isupper(grid[v.first][v.second])) {
						switch(grid[v.first][v.second]) {
							case 'B': if(umask & 0x1) Q.push(ppi(v, umask)); break;
							case 'Y': if(umask & 0x2) Q.push(ppi(v, umask)); break;
							case 'R': if(umask & 0x4) Q.push(ppi(v, umask)); break;
							case 'G': if(umask & 0x8) Q.push(ppi(v, umask)); break;
						}
						d[v.first][v.second][umask] = d[u.first][u.second][umask]+1;
					}
					else {
						Q.push(ppi(v, umask));
						d[v.first][v.second][umask] = d[u.first][u.second][umask]+1;
					}
				}
			}
		}
	}
	return -1;
}

int main() {
	int i, j, k, dis;
	pii start;
	//freopen("C:\\in.txt", "r", stdin);
	while(scanf("%d%d", &R, &C)==2) {
		if(!R && !C) break;
		for(i=0; i<R; i++) {
			scanf("%s", grid[i]);
			for(j=0; j<C; j++) {
				if(grid[i][j]=='*') start = pii(i, j);
				for(k=0; k<16; k++) d[i][j][k] = -1;
			}
		}
		dis = bfs(start);
		if(dis<0) printf("The poor student is trapped!\n");
		else printf("Escape possible in %d steps.\n", dis);
	}
	return 0;
}
