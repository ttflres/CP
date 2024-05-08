#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5+3;
signed main() {
	int n, k;
    cin >> n >> k;
    vector<int>p(n), pg(n);
    vector<vector<int>> f(n+1, vector<int>(k+1,0));
    for (int i=0; i<n; i++) cin>>p[i];
    for (int i=0; i<n; i++) cin >> pg[i];
    for (int i=0; i<n; i++)
    {
    	for (int j=0; j<=k; j++)
    	{
    		f[i+1][j]=f[i][j];
    		if (j>=p[i])
    			f[i+1][j]=max(f[i+1][j], pg[i]+f[i][j-p[i]]);
    	}
    }
    cout<<f[n][k];
    
}

