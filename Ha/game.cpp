#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5;

int p[maxn];
int t, a, b, c, d;

void sieve()
{
    memset(p, 1, sizeof(p));
    p[0]=0, p[1]=0;
    for (int i=2; i*i<=maxn; i++)
    {
        if (p[i])
        {
            for (int j=i*i; j<=maxn; j+=i)
                p[j]=0;
        }
    }
}

void solve() {
	cin >> a >> b >> c >> d;
	bool f;
	for(int i = a; i <= b; i++) {
		f = true;
		for(int j = c; j <= d; j++) {
			if (p[i+j]) {
				f = false;
				break;
			}
		}
		if (f) {
			cout << "Tam" << endl;
			return ;
		}
	}
	cout << "Cam" << endl;
}

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   freopen("game.inp", "r", stdin);
   freopen("game.out", "w", stdout);
   sieve();
   cin >> t;
   while (t--) solve();

}
/*
==================================================+
INPUT
--------------------------------------------------|
1
2 3 4 5

--------------------------------------------------|
==================================================+
OUTPUT                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/