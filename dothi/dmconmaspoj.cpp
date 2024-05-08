#include<bits/stdc++.h>
using namespace std;
#define int long long

int t;
int d[10][10], l[10][10];
const int dx[]={1, 1, 2, 2, -1, -1, -2, -2};
const int dy[]={-2, 2, -1, 1, 2, -2, 1, -1};

void solve()
{
    memset(d, 0, sizeof(d));
    memset(l, 0, sizeof(l));
    string a, b; cin >> a >> b;
    pair<int, int> st, en;
    st={a[0]-'a'+1, a[1]-'0'};
    en={b[0]-'a'+1, b[1]-'0'};
    queue<pair<int, int>> q;
    q.push({st.first, st.second});
    while (!q.empty())
    {
        int x=q.front().first, y=q.front().second;
        q.pop();
        for (int i=0; i<8; i++)
        {
            int nx=x+dx[i], ny=y+dy[i];
            if (nx<1||nx>8||ny<1||ny>8) continue;
            if (d[nx][ny]==0)
            {
                d[nx][ny]=1;
                l[nx][ny]=l[x][y]+1;
                q.push({nx, ny});
            }
        }
    }
    cout<<l[en.first][en.second]<<endl;
}

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   cin >> t;
   while (t--) solve();

}
