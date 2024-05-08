#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+7;

int a[maxn], n, k;

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   freopen("DGROUPS.inp", "r", stdin);
   freopen("DGROUPS.out", "w", stdout);
   cin >> n >> k;
   for (int i=1; i<=n; i++) cin >> a[i];
   sort(a+1, a+n+1);
   int pos=1, cnt=0;
   while (pos<=n)
   {
       pos=upper_bound(a+1, a+n+1, a[pos]+k)-a;
       cnt++;
   }
   cout<<cnt;

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