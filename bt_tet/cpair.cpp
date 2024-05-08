#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 7;
int d[maxn];
int main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    int res=0;
    for (int i=0; i<n; i++) cin >> a[i];
    	for (int i=0; i<n; i++)
    	{
    		d[a[i]]++;
    		int v=k-a[i]*a[i];
    		if (v>=0) res+=d[v];
    	}
    cout<<res;
    
}

