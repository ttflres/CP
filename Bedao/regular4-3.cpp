#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 7;
int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i=0; i<n; i++) cin >> a[i];
    map<int, int> mp;
    int ans=0;
    for (int i=0; i<n; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            ans+=mp[-a[i]-a[j]];
        }
        for (int t=0; t<i; t++)
        {
            mp[a[t]+a[i]]++;
        }
    }
    cout<<ans;
    
}
