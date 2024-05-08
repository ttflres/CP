#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 7;
bool check(int n)
{
	int k=sqrt(2*n);
	return k*(k+1)/2==n;
}
int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i=0; i<n; i++) cin >> a[i];
    int l=0,ans=0;
    for (int i=0; i<n; i++)
    {
    	if (check(a[i]))
    	{
    		if (i>0&&a[i-1]<=a[i]) l++;
    		else l=1;
    		ans=max(ans, l);
    	}
    	else l=0;
    }
    cout<<ans;
    
}

