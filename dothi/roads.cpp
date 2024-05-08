#include "bits/stdc++.h"
using namespace std;
const int MAXN=105,MAXK=1e4+5;
int n,m,k;
struct Edge{
	int v,dodai,giatien;
};
vector<vector<Edge>> adj;
int len[MAXN][MAXK];

void mem()
{
	for(int i=0;i<MAXN;i++)
	{
		for(int j=0;j<MAXK;j++)
		{
			len[i][j]=INT_MAX;
		}
	}
}

struct cmp{
	bool operator () (Edge a,Edge b)
	{
		return a.dodai>b.dodai;
	}
};

void digitchar()
{
	mem();
	priority_queue<Edge,vector<Edge>,cmp> pq;
	pq.push({1,0,k});
	len[1][k]=0;
	while(!pq.empty())
	{
		int u=pq.top().v;
		int cost=pq.top().giatien;
		int leng=pq.top().dodai;
		pq.pop();
		if(u==n)
		{
			cout<<leng<<'\n';
			return;
		}
		if(leng!=len[u][cost]) continue;
		for(auto it:adj[u])
		{
			int v=it.v;
			int l=it.dodai,t=it.giatien;
			if(cost>=t and len[v][cost-t]>leng+l)
			{
				len[v][cost-t]=len[u][cost]+l;
				pq.push({v,len[v][cost-t],cost-t});
			}
		}
	}
	cout<<"-1\n";
}

void solve()
{
	cin>>k>>n>>m;
	adj.assign(n+1,vector<Edge>());
	for(int i=1;i<=m;i++)
	{
		int u,v,dodai,giatien;
		cin>>u>>v>>dodai>>giatien;
		adj[u].push_back({v,dodai,giatien});
	}
	digitchar();
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}

