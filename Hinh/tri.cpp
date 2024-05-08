#include<bits/stdc++.h>
using namespace std;
#define int long long

int a, b, c, d, e, f;

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   cin >> a >> b >> c >> d >> e >> f;
   int tmp=a*(d-f)+c*(f-b)+e*(b-d);
   if (tmp==0) cout<<0;
   else cout<<1;

}
