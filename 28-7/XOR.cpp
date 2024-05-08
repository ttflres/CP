#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+7;

int bit[maxn][31];
int a[maxn], n;
int res=0;

int power(int a, int b)
{
    if (b==0) return 1;
    int t=power(a, b/2);
    t*=t;
    if (b&1) return t*a;
    return t;
}

int Or(int l, int r)
{
    int ans=0;
    for (int i=0; i<30; i++)
    {
        if (bit[r][i]-bit[l-1][i]>0)
        {
            ans+=power(2, i);
        }
    }
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    freopen("BIGBIRD.INP", "r", stdin);
    freopen("BIGBIRD.OUT", "w", stdout);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++)
    {
        for (int j=0; j<31; j++)
        {
            bit[i][j]=bit[i-1][j]+(a[i]>>j&1);
        }
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=i; j<=n; j++)
        {
            res^=Or(i,j);
            //Or(i, j);
        }
    }
    cout<<res<<endl;
}
/*
==================================================+
INPUT
--------------------------------------------------|
3
1 4 3
--------------------------------------------------|
==================================================+
OUTPUT                                            |
--------------------------------------------------|
3
--------------------------------------------------|
==================================================+
*/
