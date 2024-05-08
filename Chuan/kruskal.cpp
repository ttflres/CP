#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair <int, int>
const int maxn = 1e5+7;
int bo[maxn], cao[maxn];
int n, m, ans=0, k;
struct edge
{
    int a, b, c;
};
bool cmp(const edge &a, const edge &b)
{
    return a.c<b.c;
}
void makeset(int v)
{
    bo[v]=v;
    cao[v]=0;
}
int findset(int v)
{
    return v==bo[v] ? v : bo[v]=findset(bo[v]);
}
bool unionset(int u, int v)
{
    u=findset(u);
    v=findset(v);
    if (u==v) return false;
    if (u!=v)
    {
        if (cao[u]<cao[v]) swap(u,v);
        bo[v]=u;
        if (cao[u]==cao[v]) cao[u]++;
        return true;
    }
}


signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    for (int i=1; i<=k; i++)
    {
    	int x; cin >> x;
	}
    vector<edge>v(m);
    for (edge &e:v) cin >> e.a >> e.b >> e.c;
    sort(v.begin(), v.end(), cmp);
    for (int i=1; i<=n; i++) makeset(i);
    for (edge &e: v)
    {
        if (unionset(e.a, e.b)) ans+=e.c;
    }
    cout<<ans;
}

