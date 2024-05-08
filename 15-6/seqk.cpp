#include <bits/stdc++.h>
using namespace std;
const int MN = 1e5 + 5;

int n, k, a[MN];
void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    int l = 0, r = -1, sum = 0, res = 0;
    while (1){
        r++;
        if (l > r || r >= n) break;
        sum += a[r];
        while (sum > k) sum -= a[l++];
        if (sum == k) res = max(res, r - l + 1);
    }
    cout << res;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
