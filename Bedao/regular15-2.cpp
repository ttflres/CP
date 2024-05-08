#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define pii pair <int, int>
const int maxn = 1e5+7, mod=1e9+7;
vector<ll>v;
ll l, r;
ll to_int(string s)
{
    ll tmp=0;
    for (auto x:s) tmp=tmp*10+x-'0';
    return tmp;
}
signed main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i=1; i<=9; i++) v.push_back(to_int(to_string(i)));
    for (int i=1; i<=maxn; i++)
    {
        string s=to_string(i);
        reverse(s.begin(), s.end());
        v.push_back(to_int(to_string(i)+s));
        for (int j=0; j<=9; j++)
        {
            v.push_back(to_int(to_string(i)+to_string(j)+s));
        }
    }
    sort(v.begin(), v.end());
    // cout<<v[10];
    cin >> l >> r;
    auto it=lower_bound(v.begin(), v.end(), r)-v.begin();
    auto it1=lower_bound(v.begin(), v.end(), l)-v.begin();
    if (v[it]>r) it--;
    ll ans=0;
    for (auto i=it1; i<=it; i++)
    {
        ans+=v[i];
    }
    cout<<ans;

}
