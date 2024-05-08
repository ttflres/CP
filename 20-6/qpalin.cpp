#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 7, mod=1e9+7;
 
int n, q, p[maxn];
string s;
 
struct segtree
{
    int st[4*maxn], lazy[4*maxn];
 
	void down(int l, int r, int id)
    {
        int val=lazy[id];
        int mid=(l+r)/2;
        st[2*id]=(st[2*id]+val)%mod;
        st[2*id+1]=(st[2*id+1]+val*p[mid-l+1])%mod;
        lazy[2*id]=(lazy[2*id]+val)%mod;
        lazy[2*id+1]=(lazy[2*id+1]+val*p[mid-l+1])%mod;
        lazy[id]=0;
    };
 
    void update(int l, int r, int u, int v, int val, int id)
    {
        if (v<l||r<u) return;
        if (u<=l&&r<=v)
        {
            st[id]=(st[id]+val*(p[l-u]))%mod;
            lazy[id]=(lazy[id]+val*(p[l-u]))%mod;
            return;
        }
        down(l, r, id);
        int mid=(l+r)/2;
        update(l, mid, u, v, val, 2*id);
        update(mid+1, r, u, v, val, 2*id+1);
        st[id]=max(st[id*2],st[id*2+1]);
    }
 
    int getval(int l, int r, int i, int id)
    {
        if (i<l||r<i) return mod;
        if (l==r) return st[id];
        down(l, r, id);
        int mid=(l+r)/2;
        return min(getval(l, mid, i, 2*id), getval(mid+1, r, i, 2*id+1));
    }
 
 
};
segtree a,b;
 
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> q;
    cin >> s;
    p[0]=1;
    for (int i=1; i<=n; i++) p[i]=p[i-1]*31%mod;
    for (int i=1; i<=n; i++)
    {
        a.update(1, n, i, n, (s[i-1]-'a'+1), 1);
        b.update(1, n, i, n, (s[n-i]-'a'+1), 1);
    }
    while (q--)
    {
        int t; cin >> t;
        if (t==1)
        {
            int x; char c;
            cin >> x >> c;
            int tmp=(c-s[x-1]+mod)%mod;
            a.update(1, n, x, n, tmp, 1);
            b.update(1, n, n-x+1, n, tmp, 1);
            s[x-1]=c;
        }
        else
        {
            int l, r; cin >> l >> r;
            int A=(a.getval(1, n, r, 1)-a.getval(1, n, l-1, 1)*p[r-l+1]%mod+mod)%mod;
            int B=(b.getval(1, n, n-l+1, 1)-b.getval(1, n, n-r, 1)*p[r-l+1]%mod+mod)%mod;
            if (A==B) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
            // cout<<A<<" "<<B<<endl;
        }
        
    }
}