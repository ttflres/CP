#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

const int maxn=3e5+7;

int n, a[maxn], t;
int st[32][4*maxn], lazy[32][4*maxn];
int crr[maxn];

void down(int id, int i, int l, int r)
{
    int k=lazy[id][i];
    if (!k) return;
    if (k==1)
    {
        st[id][i]=st[id][2*i]=st[id][2*i+1]=0;
    }
    else
    {
        int mid=(l+r)/2;
        st[id][2*i]=mid-l+1;
        st[id][2*i+1]=r-mid;
    }
    lazy[id][2*i]=lazy[id][2*i+1]=k;
    lazy[id][i]=0;
}

void update(int id, int i, int l, int r, int u, int v, int val)
{
    if (v<l||r<u) return;
    if (u<=l&&r<=v)
    {
        if (!val)
        {
            st[id][i]=0;
        }
        else
        {
            st[id][i]=r-l+1;
        }
        lazy[id][i]=val+1;
        return;
    }
    down(id, i, l, r);
    int mid=(l+r)/2;
    update(id, 2*i, l, mid, u, v, val);
    update(id, 2*i+1, mid+1, r, u, v, val);
    st[id][i]=st[id][2*i]+st[id][2*i+1];
}

int get(int id, int i, int l, int r, int u, int v)
{
    if (v<l||r<u) return 0;
    if (u<=l&&r<=v)
    {
        return st[id][i];
    }
    down(id, i, l, r);
    int mid=(l+r)/2;
    return get(id, 2*i, l, mid, u, v) + get(id, 2*i+1, mid+1, r, u, v);
}

signed main() {
    freopen("mexquery.inp", "r", stdin);
    freopen("mexquery.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i=1; i<=n; i++) 
    {
        cin >> a[i];
        update(a[i], 1, 1, n, i, i, 1);
    }
    cin >> t;
    while (t--)
    {
        int tt; cin >> tt;
        int l, r; cin >> l >> r;
        if (l>r) swap(l, r);
        if (tt==1)
        {
            int type; cin >> type;
            for (int i=0; i<=30; i++)
            {
                crr[i]=get(i, 1, 1, n, l, r);
                update(i, 1, 1, n, l, r, 0);
            }
            int i=l, tmp=1, val=0;
            if (type==2)
            {
                val=30;
                tmp=-1;
            }
            while (i<=r)
            {
                if (crr[val])
                {
                    update(val, 1, 1, n, i, i+crr[val]-1, 1);
                }
                i+=crr[val];
                val+=tmp;
            }
        }
        else
        {
            for (int i=0; i<=31; i++)
            {
                if (!get(i, 1, 1, n, l, r))
                {
                    cout<<i<<endl;
                    break;
                }
            }
        }
    }
}

