#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e9 + 7;
vector<int> f(n+1,0);
int main() {
    int n;
    cin >> n;
    f[0]=1;
    for (int i=1; i<=n; i++)
    	{
    		for (int j=1; j<=6; j++)
    		{
    			if (i-j>=0)
    				f[i]=(f[i]+f[i-j])%maxn;
    		}
    	}
    cout<<f[n];
}

