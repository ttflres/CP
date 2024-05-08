#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, cnt=0;

bool scp(int n)
{
	int k=sqrt(n);
	return k*k==n;
}

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("aabbn.inp", "r", stdin);
	freopen("aabbn.out", "w", stdout);
	cin >> n;
	for (int i=1; i*i*i*i<=n; i++)
	{
		int tmp=i*i;
		if (n%tmp==0)
		{
			int k=n/tmp;
			if (tmp%2==0&&k%2==0&&scp(k))
			{
				if (k==tmp) cnt++;
				else cnt+=2;
			}
		}
	}
	cout<<cnt<<endl;
}

