#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 7;
int main() {
    int n, k=0;
    cin >> n;
    int a[n];
    for (int i=0; i<n; i++) 
    	{
    		cin >> a[i];
    		k+=a[i];
    	}
    vector<int>f(k+1,0);
	f[0]=1;
	for (int i=0; i<n; i++)
	{
		for (int j=k; j>= a[i]; j--)
		{
			f[j]|=f[j-a[i]];
		}
	}
	int cnt=0;
    for (int i=1; i<=k; i++)
    	if (f[i]) cnt++;
    cout<<cnt<<endl;
    for (int i=1; i<=k; i++)
    	if (f[i]) cout<<i<<" ";
}

