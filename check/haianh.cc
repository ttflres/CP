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

using namespace std;

const int MN = 1e5+5;
int n, m;
int t, k;
int a[MN];
int b[MN];
int ans1, ans2;

void Solve() {
	cin >> n >> m >> t >> k;
	for(int i = 1; i <= n; i++) 
		cin >> a[i];
	for(int i = 1; i <= m; i++)
		cin >> b[i];
		
	int l = 1, r = 1;
	bool f = true;
	int cur1 = 0, cur2 = 0;
	int temp = 0;
	while(l <= n || r <= m) {
		// cout << l << " " << r << " " << temp << " " << f << el;
		if (temp >= t) break;
		if (f) {
			while(a[l] <= temp) cur1 = a[l]+k,l++;
			if (temp < cur1) {
				temp = cur1;
			} 
			if (a[l] > t) ans1 += t - temp;
			else ans1 += a[l] - temp;
			cur1 = a[l] + k;
			temp = a[l];
			l++;
			f = false;
		} else {
			while(b[r] <= temp) cur2 = b[r]+k, r++;
			if (temp < cur2) {
				temp = cur2;
			}
			if (b[r] > t) ans2 += t - temp;
			else ans2 += b[r] - temp;
			cur2 = b[r] + k;
			temp = b[r];
			r++;
			f = true;
		}
	}
	cout << ans1 << " " << ans2;
}

signed main() {
	// freopen("watching.inp", "r", stdin);
	// freopen("watching.out", "w", stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
	Solve();	
}