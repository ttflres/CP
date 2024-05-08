#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 7;
int f[3005][3005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, tt, ttt; cin >> t >> tt >> ttt;
    string a, b;
    cin >> a >> b;
    int m=a.size(), n=b.size();
    for (int i=0; i<=m; i++)
    {
        for (int j=0; j<=n; j++)
        {
            if (!i||!j) f[i][j]=0;
            else if (a[i-1]==b[j-1]) f[i][j]=f[i-1][j-1]+1;
            else f[i][j]=max(f[i-1][j], f[i][j-1]);
        }
    }
    if (f[m][n])
    cout<<f[m][n];
    else cout<<-1;
}

