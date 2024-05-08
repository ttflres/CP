#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 7;
int f[3005][3005];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a;
    cin >> a;
    string b=a;
    reverse(b.begin(), b.end());
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
    string res="";
    while (m&&n)
    {
        if (a[m-1]==b[n-1])
        {
            res+=a[m-1];
            m--; n--;
        }
        else if (f[m-1][n]>f[m][n-1]) m--;
        else n--;
    }
    reverse(res.begin(), res.end());
    cout<<res;
}

