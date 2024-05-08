#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 7;

int n, cnt=maxn;
int a[maxn], b[50];
vector<int> v;

bool snt(int n)
{
    if (n<2) return false;
    for (int i=2; i*i<=n; i++)
    {
        if (n%i==0) return false;
    }
    return true;
}

void init()
{
    for (int i=1; i<=50; i++)
    {
        if (snt(i)) v.push_back(i);
    }
}

void in()
{
    int tmp=1;
    for (int i=0; i<n; i++) 
        {
            if (b[i]) tmp*=v[i];
        }
    bool flag=true;
    for (int i=0; i<n; i++) if (__gcd(a[i], tmp)==1) flag=false;
    if (flag) cnt=min(cnt, tmp);
}
void sinh(int i)
{
    for (int j=0; j<=1; j++)
    {
        b[i]=j;
        if (i==n) in();
        else sinh(i+1);
    }
}
int main() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    init();
    sinh(0);
    cout<<cnt;
}
