#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+7;

int n, q, a[maxn], pf[maxn];

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> q;
    for (int i=1; i<=n; i++)
    {
        cin >> a[i];
        pf[i]=pf[i-1]+a[i];
    }
    while (q--)
    {
        int a, b; 
        cin >> a >> b;
        cout<<pf[b]-pf[a-1]<<endl;
    }
}
