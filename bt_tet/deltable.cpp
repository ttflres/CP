#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 7;
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int n1=n;
    int cot[m+1]={0}, hang[n+1]={0};
    int o=n*m;
    while (k--)
    {
    	int a, b;
    	cin >> a >> b;
    	hang[a]++;
    	cot[b]++;
    }
    for (int i=1; i<=n; i++)
    {
    	if (hang[i]==0)
    	{
    		o-=m;
    		n1--;
    	}
    }
    for (int i=1; i<=m; i++)
    {
    	if (cot[i]==0)
    	{
    		o-=n1;
    	}
    }
    cout<<o;
}

