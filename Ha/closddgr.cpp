#include <bits/stdc++.h>

using namespace std;
#define int long long

const int maxN = 200010;

int n, m;
int timeDfs = 0, scc = 0;
int low[maxN], num[maxN];
bool deleted[maxN], d[maxN];
stack<int> st;
set <int> g[maxN];
int ans=0;

void dfs(int u) {
    num[u] = low[u] = ++timeDfs;
    st.push(u);
    for (int v : g[u]) {
    	if (deleted[v]) continue;
        if (!num[v]){
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else low[u] = min(low[u], num[v]);
    }
    if (low[u] == num[u]) {
    	vector<int> l;
        memset(d, 0, sizeof(d));
        int v;
        do {
            v = st.top();
			l.push_back(v);
			d[v]=1; 
            st.pop();
            deleted[v] = true;
        }
        while (v != u);
        int cnt=0;
        for (auto i:l)
        {
        	for (auto j:g[i])
        	{
        		if (d[j]) cnt++;
			}
		}
		ans+=l.size()*(l.size()-1)-cnt;
    }
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	freopen("closdgr.inp", "r", stdin);
	freopen("closdgr.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].insert(v);
    }
    for (int i = 1; i <= n; i++)
        if (!num[i]) dfs(i);

    cout <<ans;
}
