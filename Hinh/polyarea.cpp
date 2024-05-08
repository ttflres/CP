#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double

double a, b, c, d, e, f, g, h;

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   cin >> a >> b >> c >> d >> e >> f >> g >> h;
   double a1=d-b, b1=a-c, c1=a1*a+b1*b;
   double a2=h-f, b2=e-g, c2=a2*e+b2*f;
   if (a1*b2-a2*b1)
   {
       cout<<setprecision(3)<<fixed<<(b2*c1-b1*c2)/(a1*b2-a2*b1)<<" "<<(a1*c2-a2*c1)/(a1*b2-a2*b1);
   } else cout<<-1;
}
