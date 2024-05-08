#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int maxn = 1e5 + 7;

int f[3005][3005];
string a, b;

set<string> findLCS(string X, string Y, int m, int n)
{
    set<string> s;
    if (m == 0 || n == 0)
    {
        s.insert("");
        return s;
    }
    if (X[m - 1] == Y[n - 1])
    {
        set<string> tmp = findLCS(X, Y, m - 1, n - 1);
        for (string str : tmp)
            s.insert(str + X[m - 1]);
    }
    else
    {
        if (f[m - 1][n] >= f[m][n - 1])
            s = findLCS(X, Y, m - 1, n);
        if (f[m][n - 1] >= f[m - 1][n])
        {
            set<string> tmp = findLCS(X, Y, m, n - 1);
            s.insert(tmp.begin(), tmp.end());
        }
    }
    return s;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (fopen("NUMBER.INP", "r"))
    {
    	freopen("NUMBER.INP", "r", stdin);
    	freopen("NUMBER.OUT", "w", stdout);
	}
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
    set<string> st=findLCS(a, b, m, n);
    for (auto x:st) cout<<x<<" ";
}

