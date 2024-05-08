#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,pair<int, int>>

const int maxn = 2e5 + 7;
int n, m, k;
vector<pair<int, int>> g[maxn];
int l[maxn][6], tr[maxn];

void dick()
{
    int x=1;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i=1; i<=n; i++) for (int j=0; j<=6; j++) l[i][j]=1e18;
    l[x][0]=0;
    pq.push({0, {x, 0}});
    int i,j,c,w;
    while (!pq.empty())
    {
        c=pq.top().first;
        i=pq.top().second.first;
        w=pq.top().second.second;
        pq.pop();
        if (l[i][w]!=c) continue;
        for (auto x:g[i])
        {
            j=x.first;
            c=x.second;
            if (l[j][w]>l[i][w]+c)
            {
                l[j][w]=l[i][w]+c;
                pq.push({l[j][w], {j, w}});
            }
            if (w<k&&l[j][w+1]>l[i][w])
            {
                l[j][w+1]=l[i][w];
                pq.push({l[j][w+1], {j, w+1}});
            }

        }
    }
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    dick();
    int ans = 1e18;
    for (int i=0; i<=k; i++) ans = min(ans,l[n][i]);
    cout << (ans == 1e18 ? -1 : ans);
}