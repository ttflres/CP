#include <bits/stdc++.h>
using namespace std;

#define int long long
#define getbit(x, i) ((x >> i) & 1)
#define countbit(x) __builtin_popcountll(x);

const int mxN = 2e5 + 5;
const int inf = 1e9;

int n, l, r;
int a[mxN], f[85][mxN], pf[mxN];
pair <int, int> b[mxN];
pair <int, int> par[85][mxN];

void sub1 (void) {
    for (int i = 0; i < (1 << n); ++i) {
        int sum = 0;
        vector <int> v;
        for (int j = 0; j < n; ++j) {
            if (getbit(i, j)) {
                sum += a[j + 1];
                v.emplace_back(j + 1);
            }
        }
        if (l <= sum && sum <= r) {
            cout << v.size() << '\n';
            for (auto x : v) {
                cout << x << " ";
            }
            break;
        }
    }
}

void sub2 (void) {
    int half = n >> 1;
    vector <int> v;
    unordered_map <int, int> m;
    for (int i = 0; i < (1 << half); ++i) {
        int sum = 0;
        for (int j = 0; j < half; ++j) {
            if (getbit(i, j)) sum += a[j + 1];
        }
        if (m[sum] == 0) {
            m[sum] = i;
            v.emplace_back(sum);
        }
    }
    sort(v.begin(), v.end());
    // for (auto x : v) cout << x << " ";
    for (int i = 0; i < (1 << (n - half)); ++i) {
         int sum = 0;
         for (int j = 0; j < (n - half); ++j) {
            if (getbit(i, j)) {
                sum += a[j + 1 + half];
            }
         }
         if (sum > r) continue;
         // cout << sum << " ";
         int pos = upper_bound(v.begin(), v.end(), r - sum) - v.begin();
         if (pos == 0) continue;
         pos--;
         // cout << pos << " " << v[pos] << '\n';
         if (v[pos] + sum >= l) {
            vector <int> tmp;
            int mask = m[v[pos]];
            for (int j = 0; j < half; ++j) {
                if (getbit(mask, j)) {
                    tmp.emplace_back(j + 1);
                }
            }
            for (int j = 0; j < (n - half); ++j) {
                if (getbit(i, j)) {
                    tmp.emplace_back(j + 1 + half);
                }
            }
            cout << tmp.size() << '\n';
            for (auto x : tmp) cout << x << " ";
            break;
         }
    }
}

void sub3 (void) {
    f[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= r; ++j) {
            if (f[i - 1][j] == 1) {
                f[i][j] = f[i - 1][j];
                par[i][j] = {i - 1, j};
            }
            if (j >= a[i] && f[i - 1][j - a[i]]) {
                f[i][j] = f[i - 1][j - a[i]];
                par[i][j] = {i - 1, j - a[i]};  
            }
        }
    }
    int sum = 0;
    for (int i = l; i <= r; ++i) {
        if (f[n][i]) {
            sum = i;
            break;
        }
    }
    vector <int> v;
    while (1) {
        pair <int, int> next = par[n][sum];
        if (next.second < sum) {
            v.emplace_back(n);
        }
        n = next.first, sum = next.second;
        if (n == 0 && sum == 0) break;
    }
    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for (auto x : v) cout << x << " ";
}

void sub4 (void) {
    vector <int> v;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        v.emplace_back(i);
        sum += a[i];
        if (sum >= l) break;
    }
    cout << v.size() << '\n';
    for (auto x : v) cout << x << " ";
}

void sub5 (void) {
    vector <int> v;
    int sum = 0;
    for (int i = n; i >= 1; --i) {
        if (sum + a[i] > r) continue;
        sum += a[i];
        v.emplace_back(i);
        if (sum >= l) break;
    }
    if (sum < l) {
        cout << -1;
        return;
    }
    cout << v.size() << '\n';
    sort(v.begin(), v.end());
    for (auto x : v) cout << x << " ";
}

void sub6 (void) {
    vector <int> v;
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        b[i].first = a[i], b[i].second = i;
    }
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; ++i) {
        pf[i] = pf[i - 1] + b[i].first;
    }
    int i = 1;
    while (i <= n) {
        sum += b[i++].first;
        if (sum >= l) break;
    }
    if (sum == l || (l <= sum && sum <= r)) {
        for (int j = 1; j < i; ++j) {
            v.emplace_back(b[j].second);
        }
    } 
    else {
        int k = i - 2, li = 0;
        for (int i = k; i <= n; ++i) {
            if (pf[i] - pf[i - k] >= l) {
                // cout << i << '\n';
                li = i;
                break;
            }
        }
        if (li == 0) {
            cout << -1;
            return;
        }
        for (int i = li - k + 1; i <= li; ++i) {
            v.emplace_back(b[i].second);
        }
    }
    if (v.size() == 0) {
        cout << -1;
        return;
    }
    cout << v.size() << '\n';
    sort(v.begin(), v.end());
    for (auto x : v) cout << x << " ";
}

signed main (void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> l >> r;
    bool ok1 = 1, ok2 = 1, ok3 = 1;
    int maxa = -inf, mina = inf;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        maxa = max(maxa, a[i]);
        mina = min(mina, a[i]);
        if (a[i] != i) ok2 = 0;
        if (a[i] > 1e5) ok3 = 0;
        if (i > 1 && a[i] != a[i - 1]) ok1 = 0;
    }
    if (r - l >= maxa - mina) {
        sub6();
    }
    else if (n <= 80 && ok3) {
        sub3();
    }
    else if (ok1) {
        sub4();
    }
    else if (ok2){
        sub5();
    }
    else if (n <= 20) {
        sub1();
    }
    else if (n <= 40) {
        sub2();
    }
}