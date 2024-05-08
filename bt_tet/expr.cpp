#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main ()
{
    ll a,b,c;
    cin >> a >> b >> c;
    ll m=a*b+c, n=b*c+a, p=c*a+b, q=a*b*c, r=a+b+c;
    cout<<max(m, max(n, max(p, max(q,r))));
}
