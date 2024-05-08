#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC target("avx","sse2")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define pii pair <int, int>
const int maxn = 1e5+7, mod=1e9+7;
int n, m;
int a[maxn], b[maxn];
bool check(int mid)
{
    int cnt=0;
    for (int i=1; i<=n; i++)
    {
        auto it=upper_bound(b+1,b+n+1,mid-a[i])-b-1;
        cnt+=it;
    }
    return (cnt>=m);
}
signed main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++) cin >> b[i];
    sort(a+1,a+n+1), sort(b+1,b+n+1);
   int l=a[1]+b[1], r=a[n]+b[n], ans=0;
    while (l<=r)
    {
        int mid=(l+r)/2;
        if (check(mid)) ans=mid, r=mid-1;
        else l=mid+1;
    }
    cout<<ans;
}
