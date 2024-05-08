#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5;

pair<int, int> a[maxn];
int n;
int f[maxn];

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second<b.second;
}

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   cin >> n;
   for (int i=1; i<=n; i++)
   {
       cin >> a[i].first >> a[i].second;
       a[i].second+=a[i].first;
   }
   sort(a+1, a+n+1, cmp);
   int ans=0;
   for (int i=1; i<=n; i++)
   {
       f[i]=1;
       for (int j=1; j<i; j++)
       {
           if (a[i].first>=a[j].second) f[i]=max(f[i],f[j]+1);
       }
   }
   for (int i=1; i<=n; i++) ans=max(ans, f[i]);
   cout<<ans;

}
/*
==================================================+
INPUT
--------------------------------------------------|
7
1 6
8 6
14 5
19 2
1 8
18 3
10 6

--------------------------------------------------|
==================================================+
OUTPUT                                            |
--------------------------------------------------|
4
--------------------------------------------------|
==================================================+
*/