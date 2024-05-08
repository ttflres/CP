#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e6+5;

int phi[maxn];
int t, n;

void Phi()
{
	for (int i=0; i<=maxn; i++)
	{
		phi[i]=i;
	}
	for (int i=2; i<=maxn; i++)
	{
		if (phi[i]==i)
		{
			for (int j=i; j<=maxn; j+=i)
			{
				phi[j]-=phi[j]/i;
			}
		}
	}
}

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Phi();
	cin >> t;
	while (t--)
	{
		cin >> n;
		cout<<phi[n]<<endl;
	}
}

