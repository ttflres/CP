#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define pii pair <int, int>
const int maxn = 1e6, mod=1e9+7;
bool prime[maxn];
void sieve()
{
	for (int i=0; i<=maxn; i++) prime[i]=true;
	prime[0]=false;
	prime[1]=false;
	for (int i=2; i*i<=maxn; i++)
	{
		if (prime[i])
		{
			for (int j=i*i; j<=maxn; j+=i)
			{
				prime[j]=false;
			}
		}
	}
}
int n, k, a[maxn], p[maxn], cnt, gud[maxn], ans=maxn;
signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	sieve();
	cin >> n >> k;
	for (int i=1; i<=n; i++)
	{
		cin >> a[i];
	}
	for (int i=1; i<=n; i++)
	{
		if (prime[a[i]]&&a[i]<=k&&a[i]>0) gud[i]=1, cnt++;
	}
	for (int i=1; i<=n; i++)
	{
		p[i]=p[i-1]+(gud[i]==0);
	}
	for (int i=1; i<=n-cnt; i++)
	{
		ans=min(ans, -p[i-1]+p[i+cnt-1]);
	}
	cout<<ans;
	
}
