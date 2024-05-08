#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e6+7;
const int inf=1e18;

int st[4*maxn], lazy[4*maxn];
 
void down(int id)
{
    int val=lazy[id];
    st[2*id]+=val;
    st[2*id+1]+=val;
    lazy[2*id]+=val;
    lazy[2*id+1]+=val;
    lazy[id]=0;
}
 
void update(int id, int l, int r, int u, int v, int val)
{
    if (v<l||r<u) return;
    if (u<=l&&r<=v)
    {
        st[id]+=val;
        lazy[id]+=val;
        return;
    }
    down(id);
    int mid=(l+r)/2;
    update(2*id, l, mid, u, v, val);
    update(2*id+1, mid+1, r, u, v, val);
    st[id]=max(st[id*2], st[id*2+1]);
}
 
int get(int id, int l, int r, int u, int v)
{
    if (v<l||r<u) return -inf;
    if (u<=l&&r<=v)
    {
        return st[id];
    }
    down(id);
    int mid=(l+r)/2;
    return max(get(2*id, l, mid, u, v), get(2*id+1, mid+1, r, u, v));
}

struct vcl
{
	int l, r, w;
	bool operator < (const vcl &o) const
	{
		return l<o.l;
	}
};

vcl a[maxn];
int n;
vector<int> v, en[maxn];

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i=1; i<=n; i++) cin >> a[i].l >> a[i].r >> a[i].w;
	sort(a+1, a+n+1);
	int ans=0;
	for (int i=n; i>=1; i--)
	{
		int j=i;
		while (a[j].l==a[i].l)
		{
			update(1, 1, maxn, a[j].r, maxn, a[j].w);
			j--;
			if (j==0) break;
		}
//		cout<<j<<endl;
		cout<<get(1, 1, maxn, a[i].l, maxn)<<endl;
		ans=max(ans, get(1, 1, maxn, a[i].l, maxn));
		if (j==0) break;
		else i=j+1;
	}
	cout<<ans;
}

