#include <bits/stdc++.h>
#define int long long
#define pb push_back
#define el "\n"
#define F first
#define S second
#define pii pair<int,int>
using namespace std;

const int MN = 1e5+5;
int n;
int a[MN], pre[MN], suf[MN], cnt[MN];
set<pii> s;
bool f = true;

int Delete() {
	int x = (*s.begin()).S;
	s.erase(s.begin());
	return x;
}

int Merge(int l, int r) {
	if (a[l] == a[r]) {
		if (s.find({-cnt[l], l}) != s.end()) {
			s.erase(s.find({-cnt[l], l}));
		}
		if (s.find({-cnt[r], r}) != s.end()) {
			s.erase(s.find({-cnt[r], r}));
		}
		cnt[l] += cnt[r];
		Merge(l, suf[r]);
		return 1;
	}
	suf[l] = r;
	pre[r] = l;
	return 0;
}

void Solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int q = 0;
	for(int i = 1; i <= n+1; i++) {
		if (a[i] != a[i-1]) {
			pre[i] = q;
			suf[q] = i;
			cnt[q] = i-q;
			s.insert({-cnt[q],q});
			q = i;
		}
	}
	int x = n;
	while (f) {
		f = false;
		int id = Delete();
		while (cnt[id] >= 3) {
			f = true;
			x -= cnt[id];
			if (Merge(pre[id], suf[id]) == 0) {
				break;
			}
			id = pre[id];
		}
	}
	cout << x << el;
	for (int i = suf[0]; i <= n; i = suf[i]) {
		for (int j = 1; j <= cnt[i]; j++) {
			cout << a[i] << " ";
		}
	}
}

signed main() {
	freopen("BALLSHOT.inp", "r", stdin);
	freopen("BALLSHOT.out", "w", stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	Solve();
}