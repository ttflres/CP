#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e9 + 7;
int main() {
    int n;
    cin >> n;
    vector<int>f(n+1,maxn);
    f[0]=0;
    for (int i=1; i<=n; i++)
    {
    	int tmp=i;
    	while (tmp>0)
    	{
    		f[i]=min(f[i], f[i-tmp%10]+1);
    		tmp/=10;
    	}
    }
    cout<<f[n];
    
}

