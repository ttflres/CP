#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+7, mod=1e9+7;
int f[maxn], inv[maxn];
int t, n, m;

int power(int a, int b, int mod)
{
    if (b == 0) return 1;
    int t = power(a, b / 2, mod);
    t = (t * t) % mod;
    if (b % 2 == 1) t = (t * a) % mod;
    return t%mod;
}


int C(int n, int k) {
    if (k > n) return 0;
    return f[n] * inv[k] % mod * inv[n - k] % mod;
}

void init()
{
	f[0]=1;
	inv[0]=1;
	for (int i=1; i<=maxn; i++) 
	{
		f[i]=f[i-1]*i; f[i]%=mod;	
		inv[i]=power(f[i], mod-2, mod); inv[i]%=mod;
	}
}

signed main()
{
	freopen("CLASSROOM.INP", "r", stdin);
	freopen("CLASSROOM.OUT", "w", stdout);
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	init();
	cin >> t;
	while (t--)
	{
		cin >> m >> n;
		int ans=1;
		for (int i=1; i<=m; i++)
		{
			ans+=C(n, i);
			if (ans>=mod) ans-=mod;
			ans%=mod;
			//cout<<C(n, i)<<endl;
		}
		cout<<ans%mod<<endl;
	}
	

}

