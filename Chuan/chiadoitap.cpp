#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+7;

int n, a[maxn], k;
unordered_set<int> s1, s2;

void backtrack(int i, int target, int sum, unordered_set<int> &s)
{
    if (i==target)
    {
        s.insert(sum);
        return;
    }
    backtrack(i+1, target, sum, s);
    backtrack(i+1, target, sum+a[i], s);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    for (int i=1; i<=n; i++) cin >> a[i];
    backtrack(1, n/2+1, 0, s1);
    backtrack(n/2+1, n+1, 0, s2);
    for (auto x:s2)
    {
        if (s1.find(k-x)!=s1.end())
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
}
