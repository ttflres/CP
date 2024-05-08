#include<bits/stdc++.h>
using namespace std;

const int MN = 1e5+5;
int n, ans;
int x, y, a1 = 1e18, a2 = -1e18, b1 = -1e18, b2 = 1e18;

void Solve() {
	cin >> n;
	for(int i = 1; i <= n; i++) {
			int A1 = -1e18, A2 = 1e18, B1 = 1e18, B2 = -1e18;
		for(int i = 1; i <= 4; i++) {
			cin >> x >> y;
			A1 = max(A1, y-x);
			A2 = min(A2, y-x);
			B1 = min(B1, y+x);
			B2 = max(B2, y+x);
		}
		a1 = min(a1, A1);
		a2 = max(a2, A2);
		b1 = max(b1, B1);
		b2 = min(b2, B2);
	}
	int a = a1-a2-1;
	int b = b2-b1-1;
	int al = max(a/2, a-a/2);
	int an = min(a/2, a-a/2);
	int bl = max(b/2, b-b/2);
	int bn = min(b/2, b-b/2);

	if (abs(a1-a2)%2 || abs(b1-b2)%2)
		ans = (int) al * bl + (int) an * bn;
	else if (abs(a1-b1)%2)
		ans = (int) an * bl + (int) al * bn;
	else
		ans = (int) al * bl + (int) an * bn;

	cout << ans;
}

signed main() {
	freopen("PINPOS.inp", "r", stdin);
	freopen("PINPOS.out", "w", stdout);
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	Solve();
}