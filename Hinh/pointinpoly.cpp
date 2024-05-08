#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define x first
#define y second
const int maxn=1005;

int n, q;
pii p[maxn];

int cross(pii a, pii b, pii c)
{
    pii ab, bc;
    ab.x=b.x-a.x;
    ab.y=b.y-a.y;
    bc.x=c.x-b.x;
    bc.y=c.y-b.y;
    return ab.x*bc.y-bc.x*ab.y;
}

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   cin >> n;
   for (int i=1; i<=n; i++)
   {
       cin >> p[i].x >> p[i].y;
   }
   cin >> q;
   while (q--)
   {
       pii r; cin >> r.x >> r.y;
       bool inside=true;
       for (int i=2; i<=n; i++)
       {
           int res=cross(p[i], r, p[i-1]);
           //cout<<res<<endl;
           if (res<=0)
           {
               inside=false;
           }
       }
       if (cross(p[1], r, p[n])<=0) inside=false;
       if (inside) cout<<1<<endl;
       else cout<<0<<endl;
   }

}
