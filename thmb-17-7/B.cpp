#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+7, inf=1e18;

string s;
int m=0, num=0, d=1, l=0;
int t[maxn], a[maxn], sign[maxn], len[maxn];
int kq=-inf;

int pw(int a, int b)
{
    if (b==0) return 1;
    int tt=pw(a, b/2);
    tt*=tt;
    if (b&1) return tt*=a;
    return tt; 
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> s;
    s=s+'+';
    for (int i=0; i<s.size(); i++)
    {
        if (s[i]!='+'&&s[i]!='-')
        {
            num=num*10+s[i]-'0';
            l++;
        }
        else
        {
            // cout<<num<<endl;
            m++;
            a[m]=num;
            sign[m]=d;
            len[m]=l;
            num=0;
            d=(s[i]=='+')?1:-1; 
            l=0;
        }
    }
    // for (int i=1; i<=m; i++) cout<<a[i]<<" ";
    // for (int i=1; i<=m; i++) cout<<sign[i]<<" ";
    for (int i=1; i<=m; i++)
    {
        t[i]=t[i-1]+sign[i]*a[i];
    }
    // for (int i=1; i<=m; i++) cout<<t[i]<<" ";
    for (int i=1; i<=m; i++)
    {
        for (int j=0; j<len[i]; j++)
        {
            int v=(a[i]/pw(10, j+1))*pw(10, j)+a[i]%pw(10, j);
            int L=t[i-1], R=t[m]-t[i];
            // cout<<L+sign[i]*v+R<<endl;
            kq=max(kq, L+sign[i]*v+R);
        }
    }
    // cout<<kq;
    for (int i=2; i<=m; i++)
    {
        int v=a[i-1]*pw(10, len[i])+a[i];
        int L=t[i-2], R=t[m]-t[i];
        kq=max(kq,L+sign[i-1]*v+R);
    }
    cout<<kq;
}