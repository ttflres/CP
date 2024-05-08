#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 2e5 + 3;
int n, k;
int a[maxn];
map<int, int> m1, m2, m;
int l[maxn], r[maxn];
int cnt=0;
signed main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cin >> n >> k;
    for (int i=1; i<=n; i++) cin >> a[i];
    for (int i=1; i<=n; i++)
    {
    	if (a[i]%k==0) l[i]+=m1[a[i]/k];
    	else l[i]=0;
    	r[n-i+1]+=m2[a[n-i+1]*k];
    	m1[a[i]]++;
    	m2[a[n-i+1]]++;
    	//cout<<l[i]<<" "<<r[i]<<endl;
    }
    for (int i=1; i<=n; i++)
    {
    	cnt+=l[i]*r[i];
    }
    cout<<cnt;
}

