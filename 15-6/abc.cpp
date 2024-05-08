#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair <int, int>
const int maxn = 1e5+7;
int pf[maxn], dak[maxn], a[maxn];
int n;
string s;
int du(char c)
{
    int l=-1, st=1;
    for (int i=0; i<n; i++)
    {
        if (s[i]==c) a[i+1]=1;
        else a[i+1]=-1;
    }
    for (int i=1; i<=n; i++) pf[i]=pf[i-1]+a[i];
    dak[n]=pf[n];
    for (int i=n-1; i>=1; i--) dak[i]=max(dak[i+1], pf[i]);
    for (int i=1; i<=n; i++)
    {
        if (dak[i]>pf[st-1])
            l=max(i-st+1,l);
        else st++;
    }
    return l;
}
signed main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    cout<<max({du('a'), du('b'), du('c')});
}
