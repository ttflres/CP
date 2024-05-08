#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+7;

int n, q, a[maxn];
vector<int> g[maxn];
int tour[maxn], stt[maxn], en[maxn];
int m=0;
int st[4*maxn], lazy[4*maxn];
 
void down(int id)
{
    int val=lazy[id];
    st[2*id]+=val;
    st[2*id+1]+=val;
    lazy[2*id]+=val;
    lazy[2*id+1]+=val;
    lazy[id]=0;
}
 
void update(int l, int r, int u, int v, int val, int id)
{
    if (v<l||r<u) return;
    if (u<=l&&r<=v)
    {
        st[id]+=val;
        lazy[id]+=val;
        return;
    }
    down(id);
    int mid=(l+r)/2;
    update(l, mid, u, v, val, 2*id);
    update(mid+1, r, u, v, val, 2*id+1);
    st[id]=(st[id*2]+st[id*2+1]);
}
 
int get(int l, int r, int u, int v, int id)
{
    if (v<l||r<u) return 0;
    if (u<=l&&r<=v)
    {
        return st[id];
    }
    down(id);
    int mid=(l+r)/2;
    return (get(l, mid, u, v, 2*id)+get(mid+1, r, u, v, 2*id+1));
}

void dfs(int x, int p) {
	++m;
	stt[x]=m;
	for (auto u:g[x])
	{
		if (u!=p) dfs(u, x);
	}
	en[x]=m;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> q;
    for (int i=1; i<n; i++)
    {
    	int u, v; cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
	}
    dfs(1, 0);
    while (q--)
    {
    	int t; cin >> t;
    	if (t==1)
    	{
    		int u, v; cin >> u >> v;
    		update(1, n, stt[u], en[u], v, 1);
		}
		else
		{
			int u; cin >> u;
			cout<<get(1, n, stt[u], stt[u], 1)<<endl;
		}
	}
}
