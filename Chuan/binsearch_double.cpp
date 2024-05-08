#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

const int maxn=1e5+7;
const double pi=acos(-1.0);

int n, m;
double a[maxn], ans=0;

bool check(double mid)
{
    int cnt=0;
    for (int i=1; i<=n; i++)
    {
        cnt+=(int)(a[i]/mid);
    }
    return (cnt>=m);
}

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   cin >> n >> m;
   for (int i=1; i<=n; i++)
   {
       double h, r; cin >> h >> r;
       a[i]=(pi*h*r*r);
   }
   double l=0, r=1e9;
   while (r-l>=1e-6)
   {
       double mid=l-(l-r)/2;
       if (check(mid))
       {
           ans=mid;
           l=mid;
       }
       else r=mid;
   }
   cout<<setprecision(6)<<fixed<<ans;

}
