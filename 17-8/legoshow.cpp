#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+7;

int n, k, a[maxn], st[4*maxn];
int ll[maxn], r[maxn];

void build(int id, int l, int r)
{
	if (l==r)
	{
		st[id]=ll[l];
		return;
	}
	int mid=(l+r)/2;
	build(2*id, l, mid);
	build(2*id+1, mid+1, r);
	st[id]=max(st[2*id], st[2*id+1]);
}

int get(int id , int l , int r , int u , int v){
		if (l > v || r < u) return 0;
		else if (l >= u && r <= v) return st[id];
		int mid = (l + r)/2;
		return max(get(id * 2, l, mid, u, v) , get(id * 2 + 1 , mid + 1 , r , u , v));
}


signed main()
{
	freopen("LEGOSHOW.INP", "r", stdin);
	freopen("LEGOSHOW.OUT", "w", stdout);
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	for (int i=1; i<=n; i++) cin >> a[i];
	sort(a+1, a+n+1);
	for (int i=1; i<=n; i++)
	{
		auto it=upper_bound(a+1, a+n+1, a[i]+k)-a-1;
		ll[i]=it-i+1;
		r[i]=it;
	}
	build(1, 1, n);
	int ans = LLONG_MIN;
	for ( int i = 1 ; i <= n ; i++ ){
		int val = get(1 , 1 , n , r[i] + 1 , n);
		ans = max(ans , ll[i] + val);
	}
	cout << ans;
}

