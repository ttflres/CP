#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+7;

int n, q, parent[maxn], sz[maxn];

void make_set(int u)
{
   parent[u]=u;
   sz[u]=1;
}

int find_set(int u)
{
   return (u==parent[u]) ? u :parent[u]=find_set(parent[u]);
}

void union_set(int x, int y)
{
   x=find_set(x), y=find_set(y);
   if (x!=y)
   {
      if (sz[x]>sz[y]) swap(x,y);
      parent[y]=x;
      sz[x]+=sz[y];
   }
}

signed main()
{
   ios_base::sync_with_stdio(false); cin.tie(NULL);
   cin >> n >> q;
   for (int i=1; i<=n; i++) make_set(i);
   while (q--)
      {
         int a, b, c;
         cin >> a >> b >> c;
         if (a==1) union_set(b, c);
         else
         {
            b=find_set(b), c=find_set(c);
            if (b==c) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
         }
      }
}