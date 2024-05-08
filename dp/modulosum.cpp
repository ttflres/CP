#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e9 + 7;
int main() {
    int n, m;
    cin >> n >> m;
    int a[n+1];
    int f[n+1][m-1];
    for (int i=1; i<=n; i++)
    {
    	for (int j=0; j<=m-1; j++)
    		f[i][j]=0;
    }
    for (int i=1; i<=n; i++) 
    {
    	cin >> a[i];
    	a[i]%=m;
    }
    for (int i=1; i<=m-1; i++)
    {
    	f[1][i]=-maxn;
    }
    f[1][a[1]]=1;
    for (int i=2; i<=n; i++)
    {
    	for (int j=0; j<=m-1; j++)
    	{
    		f[i][j]=max(f[i-1][j], f[i-1][(j-a[i]+m)%m] + 1);
    	}
    }
    if (f[n][0]!=0) cout<<"YES";
    else cout<<"NO";
}

