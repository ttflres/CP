#include<bits/stdc++.h>
using namespace std;
const int n=1e6;
int minPrime[n + 1];
void sieve()
{
	for (int i = 2; i * i <= n; ++i) {
    if (minPrime[i] == 0) { 
        for (int j = i * i; j <= n; j += i) {
            if (minPrime[j] == 0) {
                minPrime[j] = i;
            }
        }
    }
}
	for (int i = 2; i <= n; ++i) {
    	if (minPrime[i] == 0) {
        minPrime[i] = i;
    }
}
}
int factorize(int n) {
    set <int> res;
    while (n != 1) {
        res.insert(minPrime[n]);
        n /= minPrime[n];
    }
    return res.size();
}
int f[8][n];
void preprocess()
{
	sieve();
	for (int i=1; i<=7; i++)
	for (int j=1; j<=n; j++)
	{
		if (factorize(j)==i) f[i][j]=f[i][j-1]+1;
		else f[i][j]=f[i][j-1];
	}
}
int a, b, k, q;
signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	preprocess();
	cin >> q;
	while (q--)
	{
		cin >> a >> b >> k;
		cout<<f[k][b]-f[k][a-1]<<endl;
	}
	

}
