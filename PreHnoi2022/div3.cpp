#include<bits/stdc++.h>
using namespace std;
#define int long long

int a, b;

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   cin >> a >> b;
   if ((b-a)%3!=0) cout<<-1;
   else cout<<a+(b-a)/3<<" "<<a+((b-a)/3)*2;

}
/*
==================================================+
INPUT
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/