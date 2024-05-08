#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf =1e9;
struct Node{
	int u,dist;
};
 
struct Edge{
	int v,w;
};
 
struct cmp{
	bool operator ()(Node a, Node b){
		return a.dist > b.dist;
	}
};
 
vector <Edge> adj[200001];
bool visited[200001];
int n,m;
int d[200001]{};

void dijkstra(){
	priority_queue<Node , vector<Node> , cmp> h;
	queue<int> q;
	memset(visited , false , sizeof(visited));
	h.push({1,0});
	for (int i=1;i<=n;i++) d[i]=inf;
	d[1]=0;
	while(h.size()){
		Node x = h.top();
		h.pop();
		if (visited[x.u]) continue;
		visited[x.u]= true;
 
		
		for (Edge k:adj[x.u])
		for (Edge e : adj[k.v]){
			if (d[e.v] > d[x.u] + e.w *k.w) {
				d[e.v] = d[x.u] + e.w *k.w;
				h.push({e.v,d[e.v]});
			}
		}
	}
}

main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i=1;i<=m;i++){
		int u,v,w;
		cin >> u >> v >> w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	dijkstra();
	if (d[n]==inf) cout<<-1;
	else cout<<d[n];
}
