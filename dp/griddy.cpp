#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 7;
int f[1000][1000];
char a[1000][1000];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i=0; i<n; i++)
    {
    	for (int j=0; j<m; j++)
    	{
    		cin >> a[i][j];
    	}
    }
    f[0][0]=(a[0][0]=='.');
    for (int i=0; i<n; i++)
    {
    	for (int j=0; j<m; j++)
    	{
    		if (a[i][j]!='#')
    		{
			if (i-1>=0&&a[i-1][j]!='#') f[i][j]=(f[i][j]+f[i-1][j])%mod;
    		if (j-1>=0&&a[i][j-1]!='#') f[i][j]=(f[i][j]+f[i][j-1])%mod;
    	}
    		}
    		
    }
    cout<<f[n-1][m-1];
}

