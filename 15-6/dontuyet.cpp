#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 7, mod=1e9+7;
int n, m;
int a[maxn];
int f[1001][1001];
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=0; i<=n; i++) f[i][0]=1;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            f[i][j]=(f[i-1][j]+f[i-1][j-1]*a[i])%mod;
        }
    }
    cout<<f[n][m];
}
