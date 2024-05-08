#include<bits/stdc++.h>
using namespace std;
#define int long long

int x, k;

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("timsobenhat.inp", "r", stdin);
	freopen("timsobenhat.out", "w", stdout);
	cin >> x >> k;
	cout<<k/(__gcd(x, k));
}

