#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 7;
int main() {
    int b, n;
    cin >> b >> n;
    string s;
    cin >> s;
    int i,j;
    for (int t=0; t<s.size(); t++)
    {
      if (s[t]-'0'>0) 
        {
          j=t;
        }
    }
    s[j]-=1;
    for (int t=j-1; t>=0; t--)
    {
      if (s[t]-'0'<=b-2)
      {
        i=t;
        s[i]+=1;
        break;
      }
    }
    sort(s.begin()+i+1, s.end());
    cout<<s;
    
}

