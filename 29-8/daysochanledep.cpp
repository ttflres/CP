#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=2e5+5;

int n, k;
int a[maxn];

namespace sub12
{
	int cnt=0;
	void solve()
	{
		for (int i=1; i<=n; i++)
		{
			int cnte=0, cnto=0, se=0, so=0;
			for (int j=i; j<=n; j++)
			{
				if (a[j]&1) 
				{
					cnto++;
					so+=a[j];
				}
				else
				{
					cnte++;
					se+=a[j];
				}
				if (cnte>0&&cnto>0&&0<=se-so&&se-so<=k) cnt++;
			}
		}
		cout<<cnt;
	}
}

namespace sub3
{
	int pfse[maxn], pfso[maxn];
	int cnt=0;
	void solve()
	{
		for (int i=1; i<=n; i++)
		{
			if (a[i]&1) pfso[i]=pfso[i-1]+a[i];
			else pfse[i]=pfse[i-1]+a[i];
		}
		for (int i=1; i<=n; i++)
		{
			if (pfse[i]!=0)
			{
				int l=1, r=i, tmp=-1;
				while (l<=r)
				{
					int mid=(l+r)/2;
					if (pfso[mid]==pfse[i])
					{
						tmp=mid;
//						cout<<pfse[i]<<" "<<mid<<endl;
						break;
					}
					else if (pfso[mid]>pfse[i]) r=mid-1;
					else l=mid+1;
				}
				if (tmp!=-1) cnt++;	
				l=i, r=n, tmp=-1;
				while (l<=r)
				{
					int mid=(l+r)/2;
					if (pfso[mid]==pfse[i])
					{
						tmp=mid;
//						cout<<pfse[i]<<" "<<mid<<endl;
						break;
					}
					else if (pfso[mid]>pfse[i]) r=mid-1;
					else l=mid+1;
				}
				if (tmp!=-1) cnt++;	
			}
		}
		cout<<cnt;
	}
}

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("DAYSOCHANLEDEP.INP", "r", stdin);
	freopen("DAYSOCHANLEDEP.OUT", "w", stdout);
	cin >> n >> k;
	for (int i=1; i<=n; i++) cin >> a[i];
	if (n<=2000&&k!=0) sub12::solve();
	else sub3::solve();
}

