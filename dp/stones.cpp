#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 7;
int main() {
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i=0; i<n; i++) cin >> a[i];
    vector<bool> f(k+1,false);
    for (int i=1; i<=k; i++)
    {
    	f[i]=false;
    	for (int j=0; j<n; j++)
    	{
    		if (a[j]>i) break;
    		else if (!f[i-a[j]]) 
    			{
    				f[i]=true;
    				break;
    			}
    	}
    }   
    if (f[k]==true) cout<<"First";
    else cout<<"Second";
}

