#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+7;

int n, t[maxn], x;
int res = 0;

int calc(int x) {
	int ans = 0;
	for (; x<maxn; x+=x&-x) ans += t[x];
	return ans;
}

void update(int x) {
	for (; x>0; x-=x&-x) t[x]++;
}

main() {
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> x;
		res+=calc(x+1);
		update(x);
	}
	cout<<res;
}
