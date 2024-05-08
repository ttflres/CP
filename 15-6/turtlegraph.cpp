#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 3e5 + 5;
const int MOD = 998244353;

int q, n, m;
vector<int> adj[N];
bool vis[N];
bool col[N];
int cnt = 0, sz = 0;
int ans = 0;
bool chim = 0;

int Mul(int a, int b) {
    return 1LL * a * b % MOD;
}

void Sadd(int& a, int b) {
    if ((a += b) >= MOD) a -= MOD;
}

void Smul(int& a, int b) {
    a = a * b % MOD;
}

int Add(int a, int b) {
    if ((a += b) >= MOD) a -= MOD;
    return a;
}

int Pow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = Mul(res, a);
        a = Mul(a, a);
        b >>= 1;
    }
    return res;
}

void dfs(int u) {
    sz++;
    vis[u] = 1;
    cnt += col[u];
    for (int v : adj[u]) {
        if (!vis[v]) {
            col[v] = !col[u];
            dfs(v);
        } else {
            if (col[v] == col[u]) {
                chim = 0;
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ans = 1;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cnt = 0, sz = 0, chim = 1;
            dfs(i);
            if (!chim) {
                ans = 0;
                break;
            }
            Smul(ans, Add(Pow(2, cnt), Pow(2, sz - cnt)));
        }
    }

    cout << ans << '\n';
}

void clean() {
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        vis[i] = false;
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);

    cin >> q;
    while (q--) {
        solve();
        clean();
    }
}