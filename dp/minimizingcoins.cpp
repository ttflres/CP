#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e6+1;
int main() {
	int n, x;
	cin >> n >> x;
	int a[n];
	vector<int> f(x+1, maxn);
	f[0]=0;
	for (int i=0; i<n; i++) cin >> a[i];
	for (int i=1; i<=x; i++)
	{
		for (int j=0; j<n; j++)
		{
			if (i-a[j]>=0) f[i]=min(f[i], f[i-a[j]]+1);
		}
	}
	if (f[x]==maxn) cout<<-1;
	else cout<<f[x];
    
    
}

