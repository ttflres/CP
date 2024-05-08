#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+7;

int n,m,d[maxn],cnt;
vector<int> g[maxn];


void dfs(int u){
	d[u] = 1;
	for(int v : g[u]){
		if(d[v] != 0) continue;
		dfs(v);
		d[u] += d[v];
	}
	if(d[u] % 2 == 0) cnt++;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	if(n%2){
	    cout << -1;
	    return 0;
	}
	for(int i = 0;i<n-1;i++) {
		int u,v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1);
	cout << cnt - 1;
}
