#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+7;

int n, m;
int a[1010][1010];

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            char x; cin >> x;
            if (x=='.') a[i][j]=1;
            else a[i][j]=2;
        }
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            if (a[i-1][j]!=1&&a[i+1][j]!=1&&a[i][j-1]!=1&&a[i][j+1]!=1)
            {
                a[i-1][j]=0;
                a[i+1][j]=0;
                a[i][j-1]=0;
                a[i][j+1]=0;
            }
            if (a[i-1][j-1]!=1&&a[i-1][j+1]!=1&&a[i+1][j+1]!=1&&a[i+1][j-1]!=1&&a[i][j]!=1)
            {
                a[i-1][j-1]=0;
                a[i-1][j+1]=0;
                a[i+1][j+1]=0;
                a[i+1][j-1]=0;
                a[i][j]=0;
            }
        }
    }
    bool flag=true;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            if (a[i][j]==2) flag=false;
        }
    }
    if (!flag) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}
