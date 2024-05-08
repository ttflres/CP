#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5 + 3;
void solve()
{
 ll n, k;
 cin >> n >> k;
 ll a[n+1];
 for (int i=1; i<=n; i++) cin >> a[i];
 ll prefix[n+1]={0};
 for (int i=1; i<=n; i++)
 {
    prefix[i]=prefix[i-1]+a[i];
 } 
 ll l=0;
 ll res=0;
 while (l<=n-k)
 {
    ll r=l+k;
    res=max(res,prefix[r]-prefix[l]);
    l++;
    
 }
 cout<<res;
 
   
}
int main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   solve();
 
}
