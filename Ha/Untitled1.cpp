#include<bits/stdc++.h>
#define int long long
#define double long double
#define PB push_back
#define maxn 100007
#define bit(x,i) ((x>>i)&1)
#define S second
#define F first
#define MP make_pair
#define epsilon 0.000001

using namespace std;

typedef pair<int,int> pii;
typedef pair<double,double> pdd;
const int inf = 1e18;
const int mod = 1e9+7;
const double PI = acos(-1);

int n,q,a[maxn],st[20][4*maxn],lz[20][4*maxn];

void readData(){
    cin>>n;
    for (int i=1;i<=n;i++) cin>>a[i];
}

void upd(int tt, int id, int l, int r, int u, int v){
    if (u>r||v<l) return;
    if (u<=l&&r<=v){
        st[tt][id]=r-l+1-st[tt][id];
        lz[tt][id]^=1;
        return;
    }
    int mid=(l+r)/2;
    upd(tt,id*2,l,mid,u,v);
    upd(tt,id*2+1,mid+1,r,u,v);
    st[tt][id]=st[tt][id*2]+st[tt][id*2+1];
    if (lz[tt][id]) st[tt][id]=r-l+1-st[tt][id];
}

int get(int tt, int id, int l, int r, int u, int v, int f){
    if (u>r||v<l) return 0;
    if (u<=l&&r<=v){
        if (f) return r-l+1-st[tt][id];
        return st[tt][id];
    }
    int mid=(l+r)/2;
    f^=lz[tt][id];
    int res=get(tt,id*2,l,mid,u,v,f)+get(tt,id*2+1,mid+1,r,u,v,f);
    f^=lz[tt][id];
    return res;
}

void solve(){
    for (int i=0;i<20;i++)
        for (int j=1;j<=n;j++)
            if (bit(a[j],i)) upd(i,1,1,n,j,j);
    cin>>q;
    while (q--){
        int k;
        cin>>k;
        if (k==1){
            int l,r;
            cin>>l>>r;
            int ans=0;
            for (int i=0;i<20;i++) ans+=pow(2,i)*get(i,1,1,n,l,r,0);
            cout<<ans<<"\n";
        }
        else{
            int l,r,x;
            cin>>l>>r>>x;
            for (int i=0;i<20;i++){
                if (!bit(x,i)) continue;
                upd(i,1,1,n,l,r);
            }
        }
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    readData();
    solve();
    return 0;
}


