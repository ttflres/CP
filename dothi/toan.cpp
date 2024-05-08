#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+7;
const int inf=1e18;

int d[maxn], k;
set<pair<int, int>> st;

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   cin >> k;
   fill(d, d+k+1, inf);
   for (int i=1; i<=9; i++)
   {
       int tmp=i%9;
       if (d[tmp]>i)
       {
           st.erase({d[tmp], tmp});
           d[tmp]=i;
           st.insert({d[tmp], tmp});
       }
   }
   while (!st.empty())
   {
       int u=st.begin()->second;
       st.erase(st.begin());
       for (int i=0; i<=9; i++)
       {
           int tmp=(u*10+i)%k;
           if (d[tmp]>d[u]+i)
           {
               st.erase({d[tmp], tmp});
               d[tmp]=d[u]+i;
               st.insert({d[tmp], tmp});
           }
       }
   }
   cout<<d[0];

}
