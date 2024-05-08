#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
#define int long long
#define pb push_back

int q,n,st[4*maxn],a[maxn];
int dp[maxn];

void build(int id , int l , int r) {
	if (l == r) {
		st[id] = dp[l];
		return;
	}
	int mid = (l+r)>>1;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	st[id] = min(st[2*id],st[2*id+1]);
	
}
void update(int id, int l , int r , int pos , int val) {
	if (l >pos|| r < pos) return;
	if (l == r && r == pos)  {
		st[id] = val;
		return;
	}
	int mid = (l+r)>>1;
	update(id*2,l,mid,pos,val);
	update(id*2+1,mid+1,r,pos,val);
	st[id] = min(st[2*id],st[2*id+1]);
}
int get(int id , int l , int r , int x , int y) {
	if (l >  y || r <  x) return 1e18;
    if (l >= x && r <= y) return st[id];
    int mid = (l+r)>>1;
    return min(get(id*2,l,mid,x,y),get(id*2+1,mid+1,r,x,y));
}
struct dat {
	int x,y,z;
};
bool cmp(dat xx , dat xy) {
	if (xx.x == xy.x) return xx.y < xy.y;
	return xx.x < xy.x;
}
vector<dat> g;

signed main(){
 	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> q >> n;
    for (int i=0; i<=n; i++) dp[i] = 1e18;
    dp[0] = 0;
    build(1,0,n);
    for (int i=0; i<q; i++)
	{
    	int q ,w;
    	cin >> q >> w;
    	g.pb({q,w,1});
    }
    sort(g.begin(),g.end(),cmp);
    for (int i=0; i<q; i++) {
    	int lft = g[i].x;
    	int rght = g[i].y;
    	int val = 1;
    	int newval = get(1,0,n,lft-1,rght-1);
    	dp[rght] = min(dp[rght], newval + val);
    	update(1,0,n,rght,dp[rght]);
    }
    if (dp[n]<1e18) cout << dp[n];
    else cout << -1;
    return 0;
}
