#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>

const int maxn=2e5+7;

struct node
{
	int dis, u, w;
	node() {};
	node (int _dis, int _u, int _w) : dis(_dis), u(_u), w(_w) {
	};	
};

class compare
{
	public:
		bool operator () (const node &a, const node &b)
		{
			return a.dis>b.dis;
		}
};

int n, m, k;
vector<pii> g[maxn];
int l[maxn][2], tr[maxn];

void dijkstra()
{
	for (int t=0; t<=6; t++)
	for (int i=1; i<=n; i++) l[i][t]=1e18;
	priority_queue<node, vector<node>, compare> pq;
	l[1][0]=0;
	pq.push({0, 1, 0});
    tr[1]=0;
	while (!pq.empty())
	{
		int i=pq.top().u, c=pq.top().dis, w=pq.top().w;
		pq.pop();
		if (l[i][w]!=c) continue;
		for (auto x:g[i])
		{
			c=x.first;
			int j=x.second;
			if (l[j][w]>l[i][w]+c)
			{
				l[j][w]=l[i][w]+c;
				pq.push({l[j][w], j, w});
                tr[j]=max(tr[i], c);
			}
			if (w<1&&l[j][w+1]>l[i][w])
			{
				l[j][w+1]=l[i][w];
				pq.push({l[j][w+1], j, w+1});
			}
		}
	}
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> k;
	for (int i=1; i<=m; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		g[u].push_back({w, v});
		g[v].push_back({w, u});
	}
	dijkstra();
	// for (int i=1; i<=n; i++) cout<<l[i][0]<<" "<<l[i][1]<<endl;
    while (k--)
    {
        int s,t; cin >> s >> t;
        cout<<min({l[s][0], l[s][0]-tr[s]+t, l[s][1]+t})<<endl;
    }
}