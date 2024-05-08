#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=3e5+7;

int n, k, a[maxn];
int prv[maxn], nxt[maxn], pf[maxn], mxpf[maxn], mxsf[maxn];
pair<int, int> b[maxn];

signed main() {
    freopen("maxsub.inp", "r", stdin);
    freopen("maxsub.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for (int i=1; i<=n; i++)
    {
        cin >> a[i];
        b[i]={a[i], i};
        prv[i]=i-1;
        nxt[i]=i+1;
        pf[i]=pf[i-1]+a[i];
    }
    sort(b+1, b+n+1);
    int ans=0;
    for (int i=1; i<=n-k; i++)
    {
        int v=b[i].first, id=b[i].second;
        int l=id;
        //k cho chua dien
        for (int j=1; j<=k; j++)
        {
            if (!prv[l]) break;
            l=prv[l];
        }
        //tinh tong hien tai
        int r=l;
        int sum=a[l];
        for (int j=1; j<=k; j++)
        {
            r=nxt[r];
            sum+=a[r];
        }
        sum-=a[id];
        //cap nhat ket qua
        while (l!=nxt[id]&&r!=n+1)
        {
            ans=max(ans, pf[r]-pf[l-1]-sum+mxsf[l]+mxpf[r]);
            sum-=a[l];
            l=nxt[l], r=nxt[r];
            if (r!=n+1)
            {
                sum+=a[r];
            }
        }
        //cap nhat pf, sf
        if (prv[id])
        {
            int t=prv[id];
            mxpf[t]=max(mxpf[t], pf[id]-pf[t]+mxpf[id]);
        }
        if (nxt[id]!=n+1)
        {
            int t=nxt[id];
            mxsf[t]=max(mxsf[t], pf[t-1]-pf[id-1]+mxsf[id]);
        }
        nxt[prv[id]]=nxt[id];
        prv[nxt[id]]=prv[id];
    }
    cout<<ans;
}

