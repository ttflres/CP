#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 7, mod=1e9+7;
int f[maxn],inv[maxn];
int power(int a,int b, int mod)
{
    if (b == 0) 
        return 1;
    long long t = power(a, b / 2, mod);         
    t = (t * t) % mod; 
    if (b % 2 == 1) 
        t = (t * a) % mod;
    return t;
} 
int C(int n, int k)
{
	if (n<k) return 0;
	return (f[n]*inv[k]%mod*inv[n-k]%mod)%mod;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	f[0]=0;
	f[1]=1;
	inv[0]=1;
	for (int i=2; i<=maxn; i++) f[i]=(f[i-1]*i)%mod;
	for (int i=1; i<=maxn; i++) inv[i]=power(f[i], mod-2, mod);
	int n, k;
	cin >> n >> k;
	int a[n+1];
	for (int i=1; i<=n; i++) cin >> a[i];
	sort(a+1,a+n+1);
	int n1=0, n2=0;
	for (int i=1; i<=n; i++)
	{
		//cout<<(a[i]*C(i-1,k-1))%mod<<endl;
		//cout<<(a[i]*C(n-i,k-1))%mod<<endl;
		//cout<<endl;
		n1+=(a[i]*C(i-1,k-1))%mod;
		n2+=(a[i]*C(n-i,k-1))%mod;
	}
	cout<<(n1%mod-n2%mod+mod)%mod;
}



