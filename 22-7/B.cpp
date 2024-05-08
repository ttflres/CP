#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5+7, MOD=1e9+7;

int n, a[maxn], l[maxn], h[maxn];
stack<int> st;

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for(int i=1; i<=n; i++) cin >> a[i];
  	for (int i = 1; i <= n; i++) {
    while (!st.empty() && a[i] >= a[st.top()])st.pop();
	    if (st.empty()) {
		  l[i] =  a[i] * i % MOD;
		}
		else {
		  l[i] =  a[i] * (i - st.top()) % MOD + l[st.top()];
		}
	    st.push(i);
	    if (l[i] >= MOD) {
	      l[i] -= MOD;
	    }
  	}
	while (st.size()) st.pop();
	for (int i = n; i >= 1; i--) {
    while (!st.empty() && a[i] <= a[st.top()]) {
	      st.pop();
	    }
	    if (st.empty()) {
		  h[i] = 1LL * a[i] * (n - i + 1) % MOD;
		} 
		else {
		  h[i] = 1LL * a[i] * (st.top() - i) % MOD + h[st.top()];
		}
	    st.push(i);
	    if (h[i] >= MOD) {
	      h[i] -= MOD;
	    }
  	}
	int suf = 0;
	for(int i=2; i<=n; i++){
		suf += h[i];
		suf = suf % MOD;
	}
	int res = 0;
	for(int i=1; i<n; i++){
		res += l[i]*suf % MOD;
		suf -= h[i+1];
		if(suf < 0)suf += MOD;
	}
	cout << res%MOD;
}


