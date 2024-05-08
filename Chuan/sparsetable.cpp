#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+7, lg=16;

int n, q, a[maxn];
pair<int, int> st[lg+1][maxn];

pair<int, int> merge(pair<int, int>a, pair<int, int> b)
{
    if (a.first<=b.first) return a;
    else return b;
}

void preprocess() {
    for (int i = 1; i <= n; ++i) st[0][i] = {a[i], i};
    for (int j = 1; j <= lg; ++j)
        for (int i = 1; i + (1 << j) - 1 <= n; ++i)
            st[j][i] = merge(st[j - 1][i], st[j - 1][i + (1 << (j - 1))]);
}

pair<int, int> queryMin(int l, int r) {
    int k = __lg(r - l + 1);
    return merge(st[k][l], st[k][r - (1 << k) + 1]);
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> q;
    for (int i=1; i<=n; i++) cin >> a[i];
    preprocess();
    while (q--)
    {
        int l, r; cin >> l >> r;
        cout<<queryMin(l, r).second<<endl;
    }
}