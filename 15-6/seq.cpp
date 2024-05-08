#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+7;

int n, L, R, a[maxn], pf[maxn];

int find_l (int id) {
		int l = 1, r = id-1, res = -1;
		while (r >= l) {
			int mid = (r+l) >> 1;
			if (pf[id]-pf[mid] >= L) {
				res = mid;
				l = mid + 1;
			} 
			else r = mid - 1;
		}
		return res;
	}
	int find_r (int id) {
		int l = 1, r = id-1, res = -1;
		while (r >= l) {
			int mid = (r+l) >> 1;
			if (pf[id]-pf[mid] <= R) {
				res = mid;
				r = mid - 1;
			} 
			else l = mid + 1;
		}
		return res;
	}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> L >> R;
	for (int i=1; i<=n; i++) cin >> a[i];
	for (int i=1; i<=n; i++) pf[i]=pf[i-1]+a[i];
	pf[++n]=0;
	sort(pf+1, pf+n+1);
	int ans=0;
	for (int i=2; i<=n; i++)
	{
		int j1=find_l(i), j2=find_r(i);
		if (j1!=-1&&j2!=-1) ans+=(j1-j2+1);
	}
	cout<<ans;
}
