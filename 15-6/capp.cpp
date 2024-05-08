#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define pii pair <int, int>
const int maxn = 2e5+7, mod=1e9+7;
int n, k, x;
int a[maxn], f[maxn], ans;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k >> x;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=k; i<=n; i++)
    {
        map<int, int>mp;
        for (int j=i; j>i-k; j--)
        {
            mp[a[j]]++;
            //cout<<a[j]<<" "<<mp[a[j]]<<"----";
            if (mp[a[j]]>=x) {
                //cout<<a[j]<<" "<<mp[a[j]];
                f[i]++;
                mp[a[j]]=-maxn;
            }
        }
        //cout<<f[i]<<endl;
        ans=max(ans, f[i]);
    }
    cout<<ans;
}
