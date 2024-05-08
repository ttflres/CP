#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 7;
int main() {
    int t;
    cin >> t;
    while (t--)
    {
        vector<int>v;
        int cnt=0;
        int n, m;
        cin >> n >> m;
        vector<int>a;
        for (int i=0; i<n; i++)
        {
            int x;
            cin >> x;
            a.push_back(x);
        } 
        for (int i=1; i<=m; i++)
        {
            auto it=lower_bound(a.begin(), a.end(), i);
            if (it!=a.end()&&*it%i==0)
                v.push_back(*it);
            else cnt++;

        }
        if (cnt==0)
        for (auto x:v) cout<<x<<" ";
    }
    
}

