#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair <int, int>
const int maxn = 1e6+7;
int n;
int a[maxn], f[maxn];
signed main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i=1; i<=n; i++)
    {
        cin >> a[i];
    }
    f[0]=0;
    f[1] = a[1];
    f[2] = a[1] + a[2];
    for (int i=3; i<=n; i++)
    {
        f[i]=max({f[i-3]+a[i-1]+a[i],f[i-2]+a[i],f[i-1]});
    }
    cout<<f[n];
    // for ( int i=1;i<=n;i++) cout << f[i] << " ";
}
