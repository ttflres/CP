#include<bits/stdc++.h>
using namespace std;

const int maxn=1e6+3;
int f[maxn], p[maxn];
vector<int> v;
int t, n;

void sieve()
{
    memset(p, 1, sizeof(p));
    p[0]=0; p[1]=0;
    for (int i=2; i*i<=maxn; i++)
    {
        if (p[i])
        {
            for (int j=i*i; j<=maxn; j+=i)
            {
                p[j]=0;
            }
        }
    }
}

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   sieve();
   for (int i=1; i<=maxn; i++)
   {
       for (int j=i; j<=maxn; j+=i)
       {
           f[j]++;
       }
   }
   for (int i=1; i<=maxn; i++)
   {
       if (p[f[i]]) v.push_back(i);
   }
   cin >> t;
   while (t--)
   {
       int a, b; cin >> a >> b;
       auto it=lower_bound(v.begin(), v.end(), a), itt=upper_bound(v.begin(), v.end(), b);
       cout<<itt-it<<endl;
       //cout<<endl;
   }
}
/*
==================================================+
INPUT
--------------------------------------------------|
2
6 9
100 100
--------------------------------------------------|
==================================================+
OUTPUT                                            |
--------------------------------------------------|
2
0

--------------------------------------------------|
==================================================+
*/