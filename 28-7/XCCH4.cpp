#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e6;

string s;
int cnt=0;

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   freopen("XCCH4.INP", "r", stdin);
   freopen("XCCH4.OUT", "w", stdout);
   cin >> s;
   for (int i=0; i<s.size(); i++)
   {
       if ((s[i]-'0')%4==0) cnt++;
   }
   for (int i=1; i<s.size(); i++)
   {
       //cout << ((s[i-1]-'0')*10+s[i]-'0') <<" ";
       if (((s[i-1]-'0')*10+s[i]-'0')%4==0) cnt+=i;
   }
   cout<<cnt;


}
/*
==================================================+
INPUT
--------------------------------------------------|
13085
--------------------------------------------------|
==================================================+
OUTPUT                                            |
--------------------------------------------------|
5
--------------------------------------------------|
==================================================+
*/