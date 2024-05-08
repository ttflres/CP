#include<bits/stdc++.h>
using namespace std;
#define int long long


int mn;
int d[1<<18], a[1<<18], l[1<<18];
int n, L;
queue<int> q;

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> L;
	mn=(1<<L)-1;
	for (int i=1; i<=n; i++)
	{
		for (int j=L-1; j>=0; j--)
		{
			char c; cin >> c;
			if (c=='1') a[i] |= 1<<j;
		}
		int x=mn^a[i];
		l[x]=0;
		d[x]=1;
		q.push(x);
	}
	while (!q.empty())
	{
		int u=q.front();
		q.pop();
		for (int i=0; i<L; i++)
		{
			int v=u^(1<<i);
			if (!d[v])
			{
				d[v]=1;
				q.push(v);
				l[v]=l[u]+1;
			}
		}
	}
	for (int i=1; i<=n; i++) cout<<L-l[a[i]]<<endl;
}

