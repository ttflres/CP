#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define pii pair <int, int>
const int maxn = 1e6, mod=1e9+7;
int n, a[maxn], b[maxn], sum=0, mx=-maxn;
bool p[maxn];
void sieve()
{
	for (int i=0; i<=maxn; i++) p[i]=true;
	p[0]=false;
	p[1]=false;
	for (int i=2; i*i<=maxn; i++)
	{
		if (p[i])
		{
			for (int j=i*i; j<=maxn; j+=i)
			{
				p[j]=false;
			}
		}
	}
}
void in()
{
	int s=0, s1=0;
	for (int i=1; i<=n; i++)
	{
		if (b[i]==1)
		{
			s+=a[i];
		} else s1+=a[i];
	}
	// if (p[abs(sum-2*s)]) mx=max(mx, abs(sum-2*s));
	if (p[abs(s-s1)]) mx=max(mx, abs(s-s1));
}
void sinh(int i)
{
	for (int j=0; j<2; j++)
	{
		b[i]=j;
		if (i==n) in();
		else sinh(i+1);
	}
}
signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i=1; i<=n; i++) cin >> a[i], sum+=a[i];
	sieve();
	sinh(1);
	cout<<mx;
}
