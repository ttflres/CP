#include<bits/stdc++.h>
using namespace std;
#define int long long

int ssd(int n, int a[])
{
    if (n < 10)
        return (n * (n + 1) / 2);
     
    int d = (int)(log10(n));
    int p = (int)(ceil(pow(10, d)));
    int msd = n / p;
     
    return (msd * a[d] + (msd * (msd - 1) / 2) * p + msd * (1 + n % p) + ssd(n % p, a));
}
 
int sd(int n)
{
    int d = (int)(log10(n));
    int a[d + 1];
    a[0] = 0; a[1] = 45;
    for(int i = 2; i <= d; i++)
        a[i] = a[i - 1] * 10 + 45 *
               (int)(ceil(pow(10, i - 1)));
 
    return ssd(n, a);
}

signed main()
{
	freopen("SUMD.INP", "r", stdin);
	freopen("SUMD.OUT", "w", stdout);
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		cout<<sd(n)<<endl;
	}
}

