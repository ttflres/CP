#include<bits/stdc++.h>
#define el '\n'
#define int long long
using namespace std ;

const int MN = 2e5 + 10 ;
const int N = 1005;
const int mod = 1e9 + 7;

int l[MN] , r[MN] , mep[MN] , a[MN] , b[MN];

struct FenwickTree{
  vector<int> bit;
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
}it(MN);

signed main (){
	//freopen("selectrip0.INP", "r", stdin);
	//freopen("selectrip0.OUT", "w", stdout);
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for ( int i = 1 ; i <= n ; i++ ) {
    	cin >> a[i];
    	b[i] = i;
	}
    memset(mep , -1 , sizeof(mep));
    for ( int i = 1 ; i <= n ; i++ ){
    	if ( mep[a[i]] < 0 ) mep[a[i]] = 0;
    	l[i] = mep[a[i]];
    	mep[a[i]] = i;
	}
	memset(mep , -1 , sizeof(mep));
	for ( int i = n ; i >= 1 ; i-- ){
		if ( mep[a[i]] < 0 ) mep[a[i]] = n + 1;
		r[i] = mep[a[i]];
		mep[a[i]] = i;
	}
	int ans = 0;
	sort(b + 1 , b + n + 1 , [&] ( int &x , int &y ){
		return r[x] < r[y];
	});
	int pos = 1;
	for ( int i = 1 ; i <= n ; i++ ){
		while( pos < r[b[i]] ) {
			pos++;
			it.add(l[pos - 1] , 1);
		}
		ans += it.sum(0 , b[i] - 1) - i;
	}
	cout << ans;
}