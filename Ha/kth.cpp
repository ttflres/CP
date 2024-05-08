#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+7;

int n, q, a[maxn];
vector<int> v, st[4*maxn], cp;

void build(int id, int l,int r)
{
    if(l==r){
        st[id].push_back(a[l]);
        return;
    }
    int mid=(l+r)/2;
    build(2*id, l, mid);
    build(2*id+1, mid+1, r);
    merge(st[2*id].begin() , st[2*id].end(), st[2*id+1].begin(), st[2*id+1].end(),back_inserter(st[id]));
}
 
int query(int id, int l, int r, int u, int v, int val)
{
    if(l>v||r<u) return 0;
    if(u<=l&&r<=v) {
        int k = upper_bound(st[id].begin(), st[id].end(), val) - st[id].begin();
        return k;
    }
	int mid=(l+r)/2;
    return query(2*id, l, mid, u, v, val)+query(2*id+1, mid+1, r, u, v, val);
}

signed main()
{
	freopen("kthq.inp", "r", stdin);
	freopen("kthq.out", "w", stdout);
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> q;
	for (int i=1; i<=n; i++)
	{
		cin >> a[i];
		cp.push_back(a[i]);
	}
	sort(cp.begin(), cp.end());
	for (int i=1; i<=n; i++)
	{
		a[i]=lower_bound(cp.begin(), cp.end(), a[i])-cp.begin()+1;
	}
	build(1, 1, n);
	while (q--)
	{
		int l, r, x; cin >> l >> r >> x;
		int low=1, high=n, ans;
		while (low<=high)
		{
			int mid=(low+high)/2;
			int k=query(1, 1, n, l, r, mid);
			if (k>=x)
			{
				ans=mid;
				high=mid-1;
			}
			else low=mid+1;
		}
		cout<<cp[ans-1]<<endl;
	}
}

