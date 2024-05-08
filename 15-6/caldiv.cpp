#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e7+7, mod=1e9+7;

int dv[maxn], l, r;

int power(int a, int b, int mod)
{
    if (b == 0) 
        return 1;
    int t = power(a, b / 2, mod);         
    t = (t * t) % mod; 
    if (b % 2 == 1) 
        t = (t * a) % mod;
    return t;
} 

bool scp(int n)
{
	int tmp=sqrt(n);
	return tmp*tmp==n;
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> l >> r;
	for(int i = 1; i*i <= maxn; i++) {
		for(int j = max(i*i,(l+i-1)/i*i); j <= r; j+=i) dv[j]++;
	}
	int ans=0;
	for (int i=l; i<=r; i++)
	{
		if (scp(i)) ans=(ans+power(i,dv[i]-1,mod)*(int)sqrt(i))%mod;
		else ans=(ans+power(i,dv[i],mod))%mod;
	}
	cout<<ans%mod;
}
