#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

int n;
double x[102], y[102];
double res;

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   cin >> n;
   for (int i=1; i<=n; i++) cin >> x[i] >> y[i];
   for (int i=1; i<n; i++)
   {
       res+=x[i]*y[i+1]-x[i+1]*y[i];
   }
   res+=x[n]*y[1]-x[1]*y[n];
   cout<<setprecision(1)<<fixed<<res/2;

}
