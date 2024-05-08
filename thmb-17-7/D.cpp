#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 2e5 + 5;
int n, q;
int cnt[32], a[maxn], x[maxn];
int y, len;

void update_add(int p) {
    for (int i = 0; i < 30; i++) {
        if (p >> i & 1 == 1) cnt[i]++;
    }
}

void update_remove(int p) {
    for (int i = 0; i < 30; i++) {
        if ((p >> i) & 1) cnt[i]--;
    }
}

void update_xor(int p) {
    y ^= p;
    for (int i = 0; i < 30; i++) {
        if (p >> i & 1) cnt[i] = len - cnt[i];
    }
}

signed main () {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        for (int j = 0; j < 30; j++) {
            if (a[i] >> j & 1) cnt[j]++;
        }
    }
    len = n;
    while (q--) {
        int ans = 0;
        int type, p;
        cin >> type >> p;
        if (type == 1) {
            a[++n] = p;
            x[n] = y;
            update_add(a[n]);
            len++;
        }
        else if (type == 2) {
            update_remove(a[p] ^ y ^ x[p]);
            len--;
        }
        else update_xor(p);
        for (int i = 0; i < 30; i++) {
            ans += (1 << i) * (cnt[i]); 
        }
        cout << ans << '\n';
    }
}