#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e15;

int n, ans;

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   freopen("DSCQL.INP", "r", stdin);
   freopen("DSCQL.OUT", "w", stdout);
   cin >> n;
   n+=2;
   ans=sqrt(n);
   if (ans*(ans+1)<2*(n-2)) cout<<ans+1;
   else cout<<ans;

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