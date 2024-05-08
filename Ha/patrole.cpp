#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxN = 100010;

int n, m;
int timeDfs = 0, scc = 0;
int low[maxN], num[maxN];
bool deleted[maxN];
vector <int> g[maxN];
stack <int> st;
int inscc[maxN], indeg[maxN];
vector<int> g2[maxN];

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
        scc++;
        int v;
        do {
            v = st.top(); 
            inscc[v]=scc;
            st.pop();
            deleted[v] = true;
        }
        while (v != u);
    }
}

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	freopen("patrole.inp", "r", stdin);
	freopen("patrole.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 0; i < n; i++)
        if (!num[i]) dfs(i);
    for (int ii=1; ii<=n; ii++)
    {
    	int i=ii-1;
    	for (int j:g[i])
    	{
    		if (inscc[i]!=inscc[j])
    		{
    			g2[inscc[i]].push_back(inscc[j]);
    			indeg[inscc[j]]++;
			}
		}
	}
	int cnt=0;
	for (int i=1; i<=scc; i++)
	{
//		cout<<g2[i].size()<<endl;
		if (g2[i].size()==0) cnt++;
		else if (g2[i].size()>1||indeg[i]>1)
		{
			cout<<-1; return 0;
		}
	}
//	cout<<cnt<<endl;
	if (cnt!=1)
	{
		cout<<-1;
		return 0;
	}
	for (int i=1; i<=scc; i++)
	{
		if (indeg[i]==0)
		{
			for (int j=1; j<=n; j++)
			{
				int jj=j-1;
				if (inscc[jj]==i)
				{
					cout<<jj<<endl;
				}
			}	
			return 0;
		}
		
	}
}
