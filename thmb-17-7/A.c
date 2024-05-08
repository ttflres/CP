#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 7, mod=(1<<31);

int r, s;
string a[105][105];

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   cin >> r >> s;
   for (int i=1; i<=r; i++)
   {
       for (int j=1; j,=s; j++)
       {
           cin >> a[i][j];
       }
   }
   for (int i=1; i<=r; i++)
   {
       for (int j=1; j<=s; j++)
       {
           if ('0'<=a[i][j]&&a[i][j]<='100') continue;
           else cout<<"dm"<<endl;
       }
   }

}