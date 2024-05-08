#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair<int, int>
const int N=15000;
int n;
int a[N];
ii v[N];
bool cmp(ii a, ii b)
{
    return a.second<b.second;
}
int cnp(int l, int r, int x)
{
    int ans=0;
    while (l<=r)
    {
        int m=(l+r)>>1;
        if (v[m].second<=x)
        {
            ans=m;
            l=m+1;
        } else r=m-1;
    }
    return ans;
}
signed main()
{
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> v[i].first >> v[i].second;
        
    }
    sort(v+1, v+n+1, cmp);
    a[1]=v[1].second-v[1].first;
    for (int i=2; i<=n; i++)
    {
        auto p=cnp(1, i-1, v[i].first);
        a[i]=max(a[i-1], a[p]+v[i].second-v[i].first);
    }
    cout<<a[n];
}