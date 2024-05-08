#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+7;

priority_queue<int, vector<int>, greater<int>> pq;
int L, n, a[maxn], sum=0;

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	if (fopen("PARTITION.INP", "r"))
	{
		freopen("PARTITION.INP", "r", stdin);
		freopen("PARTITION.OUT", "w", stdout);
	}
	cin >> L >> n;
	for (int i=1; i<=n; i++)
	{
		cin >> a[i];
		sum+=a[i];
		pq.push(a[i]);
	}
	int ans=0;
	if (sum<L) pq.push(L-sum);
	while (pq.size()>=2)
	{
		int x=pq.top();
		pq.pop();
		int y=pq.top();
		pq.pop();
		ans+=x+y;
		if (x+y==L)
		{
			cout<<ans;
			return 0;
		}
		pq.push(x+y);
//		cout<<x+y<<endl;
	}
	if (pq.size()==1)
	{
		cout<<0;
	}
}//2001 1002

