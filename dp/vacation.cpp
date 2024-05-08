#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 7;
int n;
int a[maxn], b[maxn], c[maxn], f[maxn][3];
int main() {
    cin >> n;
    for (int i=1; i<=n; i++)
    	cin >> a[i] >> b[i] >> c[i];
    for (int i=1; i<=n; i++)
    {
    	f[i][0]=max(f[i-1][1],f[i-1][2]) + a[i];
    	f[i][1]=max(f[i-1][0], f[i-1][2]) + b[i];
    	f[i][2]=max(f[i-1][0], f[i-1][1]) + c[i];
    }
    cout<<max(f[n][0], max(f[n][1], f[n][2]));


    
}

