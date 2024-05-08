#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 7;
int f[505][505];
int main() {
    int a, b;
    cin >> a >> b;
    for (int i=1; i<505; i++) 
    {
    	for (int j=1; j<505; j++)
    	{
    		f[i][j]=INT_MAX;
    	}
    }
    for (int i=1; i<505; i++) f[i][i]=0;
    for (int i=1; i<=a; i++)
    {
    	for (int j=1; j<=b; j++)
    	{
    		for (int u=1; u<j; u++)
    		{
    			f[i][j]=min(f[i][j], f[i][u] + f[i][j-u]+1);
    		}
    		for (int v=1; v<i; v++)
    		{
    			f[i][j]=min(f[i][j], f[v][j] + f[i-v][j]+1);
    		}
    	}
    }
    cout<<f[a][b];
    
}

