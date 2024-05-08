#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 7;
int bs(int A[], int n, int target) {
    int lo = 1, hi = n;
    while (lo <= hi) {
        int mid = lo + (hi - lo)/2;
        if (A[mid] == target)
            return A[mid];         
        else if (A[mid] < target)
            lo = mid+1;
        else
            hi = mid-1;
    }
    return -1;
}       
signed main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > v;
    int a[n+1], b[m+1], c[m+1];
    for (int i=1; i<=n; i++) cin >> a[i];
    sort(a+1,a+n+1);
    for (int i=1; i<=m; i++) cin >> b[i];
    for (int i=1; i<=m; i++) cin >> c[i];
    for (int i=1; i<=m; i++)
    {
        if (bs(a,n+1,c[i])!=-1)
            v.push_back({b[i],bs(a,n+1,c[i])});
        //cout<<bs(a,n+1,c[i])<<" "<<b[i]<<endl;
    }
    cout<<v.size()<<endl;
        sort(v.begin(),v.end());
    for (auto x:v)
    {
        cout<<x.second<<" "<<x.first<<endl;
    }

    
}

