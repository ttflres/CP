#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5+5;
vector<int> a[N];
int n,m,d;
int p[N];
int st;
int dist1[N],dist2[N],lv[N];
void dfs (int u, int p, int *lv) {
    for (int i=0; i<a[u].size(); i++) {
        int v = a[u][i];
        if (v == p) continue;
        lv[v] = lv[u] + 1;
        dfs (v,u,lv);
    }
}
signed main () {
    cin >> n >> m >> d;
    for (int i=1; i<n; i++) {
        int u,v; cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for (int i=1; i<=m;i++) {
        int x; cin >> x;
        p[x] = true;
        st = x;
    }   
    dfs (1,1,lv);
    st = 0;
    for (int i=1; i<=n; i++) {
        if ((st == 0 || lv[st] < lv[i]) && p[i]) st = i;
    }
    dfs (st,st,dist1);
    int en = 0;
    for (int i=1; i<=n; i++) {
        if ((!en || dist1[en] < dist1[i])&& p[i]) en = i;
    }
    dfs (en,en,dist2);
    int ans = 0;
    for (int i=1; i<=n; i++) {
        if (dist1[i] <= d && dist2[i] <= d ) ans ++;
    }
    cout << ans;
}
