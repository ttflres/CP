#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=2e5+7;

int n, q;
int bit[maxn], last[maxn], res[maxn];

struct vcl
{
	int i, j, id, type;	
};

bool cmp(vcl a, vcl b)
{
	return (a.j<b.j||(a.j==b.j&&a.type<b.type));
}

vcl a[maxn];

void update(int x, int v)
{
	for ( ; x<=n; x+=x&(-x)) bit[x]+=v;
}

int get(int x)
{
	int res=0;
	for ( ; x>0; x-=x&(-x)) res+=bit[x];
	return res; 
}

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> q;
	for (int i=1; i<=n; i++)
	{
		cin >> a[i].i;
		a[i].j=i;
		a[i].type=-1;
	}
	for (int i=1; i<=q; i++)
	{
		cin >> a[i+n].i >> a[i+n].j;
		a[i+n].id=i;
	}
	sort(a+1, a+n+q+1, cmp);
	for (int i=1; i<=n+q; i++) {
		if (a[i].type == -1) {
			update(a[i].j, 1);
			if (last[a[i].i] > 0) update(last[a[i].i], -1);
			last[a[i].i] = a[i].j;
		} else {
			res[a[i].id] = get(a[i].j) - get(a[i].i-1);
		}
	}

	for (int i=1; i<=q; i++) cout<<res[i]<<endl;
}
