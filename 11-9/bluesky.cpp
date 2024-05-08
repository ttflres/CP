#include <bits/stdc++.h>
#define int long long
#define double long double
#define pb push_back
#define el "\n"
#define F first
#define S second
#define pii pair<int,int>
#define sz(x) (int)x.size()
#define all(x) x.begin(),x.end()
#define Test int test; cin >> test; while(test--)
//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2")
//Phucsint GOAT
//IceJam

using namespace std;

const int MN = 3e5+5;
int n, k;
int a[MN];
int d;

void Solve() {
	cin >> n >> k;
	for(int i = 1;  i <= n; i++) {
		cin >> a[i];
		if (a[i] < 0) d++;
	}
	if (k == 1 || d == 0) {
		int cur = 0, ans = LLONG_MIN;
		for(int i = 1; i <= n; i++) {
			cur = max(a[i], cur + a[i]);
			ans = max(ans,cur);
		}
		cout << ans;
	} else if (d == 1) {
		int ans = 0, cur = 0;
		a[n+1] = -1;
		for(int i = 1; i <= n+1; i++) {
			if (a[i] < 0) {
				ans += cur;
				cur = 0;
			}
			else cur += a[i];
		}
		cout << ans;
	} else {
		int cnt = 0, cur = a[1], res = 0;
		vector<int> v;
		a[n+1] = INT_MAX;
		for(int i = 2; i <= n+1; i++) {
			if ((a[i] >= 0 && a[i-1] >= 0 && a[i] != INT_MAX) || (a[i] < 0 && a[i-1] < 0 && a[i] != INT_MAX)) cur += a[i];
			else {
				if (cur >= 0) cnt++, res += cur;
				v.pb(cur);
				cur = a[i];
			}
		}
		if (cnt <= k) {
			cout << res;
		} else {
			int ans = 0;
			sort(all(v), greater<int>());
			for(int i = 0; i < k; i++)
				ans += v[i];
			
			cout << ans;
		}
	}
}

signed main() {
		freopen("FEAS.INP", "r", stdin);
	freopen("FEAS.OUT", "w", stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	Solve();	
}

