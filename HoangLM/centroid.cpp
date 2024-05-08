/*#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn=1e5+7;

int n, pa[maxn], s[maxn], ans[maxn];
vector<int> g[maxn], chain;

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
	int m=chain.size();
    int j = 0;
    for (int i = 0; i < m; ++i)
    {
        while (j<m && s[chain[j]]>s[chain[i]]/2) ++j;
        ans[chain[i]]=chain[j - 1];
    }
}

void hld(int u)
{
	chain.push_back(u);
	if (g[u].empty())
	{
		centroid(u);
		chain.clear();
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
    freopen("CENTROID.INP", "r", stdin);
    freopen("CENTROID.OUT", "w", stdout);
	cin >> n;
	for (int i=2; i<=n; i++)
	{
		int x; cin >> x;
		g[x].push_back(i);
	}
	dfs(1), hld(1);
	for (int i=1; i<=n; i++) cout<<ans[i]<<endl;
}
*/
#define taskname "CENTROID"
#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 1;

int n;
int parent[maxN], s[maxN], Result[maxN];
vector<int> children[maxN];
vector<int> List;

void ReadInput()
{
    cin >> n;
    for (int i = 2; i <= n; ++i)
    {
        int j;
        cin >> j;
        parent[i] = j;
        children[j].push_back(i);
    }
}

void DFS(int u)
{
    s[u] = 1;
    for (int v: children[u])
    {
        DFS(v);
        s[u] += s[v];
    }
}


bool Smaller(int u, int v)
{
    return s[u] < s[v];
}

void GetCentroids()
{
    int m = List.size();
    int j = 0;
    for (int i = 0; i < m; ++i)
    {
        while (j < m && s[List[j]] > s[List[i]] / 2)
            ++j;
        Result[List[i]] = List[j - 1];
    }
}

void HLD(int u)
{
    List.push_back(u);
    if (children[u].empty())
    {
        GetCentroids();
        List.clear();
        return;
    }
    int x = *max_element(children[u].begin(),
                         children[u].end(),
                         Smaller);
    HLD(x);
    for (int v: children[u])
        if (v != x) HLD(v);
}

void Print()
{
    for (int i = 1; i <= n; ++i)
        cout << Result[i] << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname".INP", "r", stdin);
    freopen(taskname".OUT", "w", stdout);
    ReadInput();
    DFS(1);
    HLD(1);
    Print();
}


