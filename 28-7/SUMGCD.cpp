#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+7, mod=1e9+7;

int n, k;
int f[maxn][21];

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   freopen("SUMGCD.INP", "r", stdin);
   freopen("SUMGCD.OUT", "w", stdout);
   cin >> n >> k;
   for (int j=1; j<=k; j++) f[1][j]=j;
   for (int i=2; i<=n; i++)
   {
       for (int j=1; j<=k; j++)
       {
           for (int t=1; t<=k; t++)
           {
               f[i][j]=__gcd(f[i][j], f[i-1][t]);
           }
       }
   }
   int ans=0;
   for (int i=1; i<=k; i++) ans+=f[n][i], ans%=mod;
   cout<<ans;

}
/*
==================================================+
INPUT
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/