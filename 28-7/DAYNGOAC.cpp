#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e6+7;

int n, q;
string s;
int a[maxn];

bool check()
{
    stack<int> st;
    for (int i=1; i<=n; i++)
    {
        if (s[i]=='(') st.push(i);
        else
        {
            if (st.empty()) return false;
            st.pop();
        }
    }
    if (st.size()) return false;
    return true;
}

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   freopen("DAYNGOAC.INP", "r", stdin);
   freopen("DAYNGOAC.OUT", "w", stdout);
   cin >> n >> q;
   cin >> s;
   s=' '+s;
   while (q--)
   {
       int x; cin >> x;
       if (s[x]=='(') s[x]=')';
       else s[x]='(';
       for (int i=1; i<=n; i++)
       {
           if (s[i]=='(')
           {
               s[i]=')';
               if (check())
               {
                   cout<<i<<" ";
                   break;
               }
               else s[i]='(';
           }
           else
           {
               s[i]='(';
               if (check())
               {
                   cout<<i<<" ";
                   break;
               }
               else s[i]=')';
           }
       }
   }

}
/*
==================================================+
INPUT
--------------------------------------------------|
6 3
((()))
4 3 1
--------------------------------------------------|
==================================================+
OUTPUT                                            |
--------------------------------------------------|
2 2 1
--------------------------------------------------|
==================================================+
*/