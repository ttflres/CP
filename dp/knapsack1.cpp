#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5+3;
int f[101][maxn];
int w[101], v[101];
signed main() {
	int n, k;
    cin >> n >> k;
    for (int i=1; i<=n; i++)
    	cin >> w[i];
    for (int i=1; i<=n; i++)
        cin >> v[i];
    memset(f,0,sizeof(f));
    for (int i=1; i<=n; i++)
    {
    	for (int j=1; j<=k; j++)
    	{
    		if (j<w[i])
    			f[i][j]=f[i-1][j];
    		else
    			f[i][j]=max(f[i-1][j], v[i]+f[i-1][j-w[i]]);
    	}
    }
    cout<<f[n][k];
    
}

