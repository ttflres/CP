#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn=1e5+7;

int n, pa[maxn], s[maxn], ans[maxn];
vector<int> g[maxn], List;

int dfs(int u)
{
	s[u]=1;
	for (auto x:g[u])
	{
		dfs(x);
		s[u]+=s[x];
	}
	return s[u];
}

bool smaller(int u, int v)
{
	return s[u]<s[v];
}

void centroid(int u)
{
	int m=List.size();
    int j = 0;
    for (int i = 0; i < m; ++i)
    {
        while (j<m && s[List[j]]>s[List[i]]/2) ++j;
        ans[List[i]]=List[j - 1];
    }
}

void hld(int u)
{
	List.push_back(u);
	if (g[u].empty())
	{
		centroid(u);
		List.clear();
		return;
	}
	int x = *max_element(g[u].begin(), g[u].end(), smaller);
    hld(x);
    for (int v: g[u]) if (v != x) hld(v);
}

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i=2; i<=n; i++)
	{
		int x; cin >> x;
		g[x].push_back(i);
	}
	dfs(1), hld(1);
	for (int i=1; i<=n; i++) cout<<ans[i]<<endl;
}
