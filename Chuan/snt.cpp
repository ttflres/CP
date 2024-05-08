#include <bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+7;

int p[maxn];

void sang_bthg()
{
	for (int i=1; i<=maxn; i++) p[i]=1;
	p[0]=0;
	p[1]=0;
	for (int i=2; i*i<=maxn; i++)
	{
		if (p[i])
		{
			for (int j=i*i; j<=maxn; j+=i)
			{
				p[j]=0;
			}
		}
	}
}

void sang_phan_tich()
{
	for (int i=2; i*i<=maxn; i++)
	{
		if (p[i]==0)
		{
			for (int j=i*i; j<=maxn; j+=i)
			{
				if (p[j]==0) p[j]=i;
			}
		}
	}
	for (int i=2; i<=maxn; i++) if (p[i]==0) p[i]=i;
}

int l, r;

void sang_doan()
{
	memset(p, 1, sizeof(p));
	for (int i=2; i*i<=r; i++)
	{
		for (int j=max(i*i, (l+i-1)/i*i); j<=r; j+=i)
		{
			p[j-l]=false;
		}
	}
	if (1>=l) p[1-l]=false;
	for (int i=l; i<=r; i++) if (p[i-l]) // la snt
}

void dem_uoc()
{
	for (int i=1; i<=maxn; i++)
	{
		for (int j=i; j<=maxn; j+=i)
		{
			p[j]++;
		}
	}
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	
}