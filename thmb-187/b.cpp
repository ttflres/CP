#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e6+7;

int n, a[maxn];

int check(int p)
{
    int cnt=0;
    for (int i=1; i<=n; i++)
    {
        if ((p&a[i])==p) cnt++;
    }
    return cnt;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];
    int res=0, cnt=0;
    for (int i=31; i>=0; i--)
    {
        cnt=(check(res|(1<<i)));
        if (cnt>=2) res=res|(1<<i);
    }
    cout<<res;
}