#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mn=5000;
const int mod=1e9+7;
int f[mn];
signed main()
{
    int n;
    cin >> n;
    if (n%4!=0&&n%4!=3)
    {
        cout<<0;
        return 0;
    }
    int sum=n*(n+1)/4;
    f[0]=1;
    for (int i=1; i<=n; i++)
    {
        for (int j=sum; j>=0; j--)
        {
            if (j-i>=0)
            {
                f[j]=(f[j]+f[j-i])%mod;
                
            }
        }
    }
    cout<<f[sum];
}