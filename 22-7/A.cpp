#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5+7;

string s;
stack<int> st;
vector<int> g[maxn];
int d[maxn], mx=-1, node;

void dfs(int x, int dd)
{
	if (dd>mx)
	{
		mx=dd;
		node=x;
	}
	d[x]=1;
	for (auto u:g[x])
	{
		if (!d[u]) dfs(u, dd+1);
	}
}

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> s;
	s=' '+s;
	st.push(0);
	int cnt=1;
	for (int i=1; i<=s.size(); i++)
	{
		if (s[i]=='(')
		{
			g[cnt].push_back(st.top());
			g[st.top()].push_back(cnt);
			st.push(cnt);
			cnt++;
		}
		else
		{
			cnt++;
			if (st.empty()) break;
			st.pop();
		}
	}
//	for (int i=1; i<=s.size(); i++)
//	{
//		for (auto x:g[i]) cout<<x<<" ";
//		cout<<endl;
//	}
	dfs(1, 0);
    mx=-1;
    for (int i=1; i<=s.size(); i++) d[i]=0;
    dfs(node, 1);
    cout<<mx-1;
}

