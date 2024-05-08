#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 7;
int d[maxn];
int main() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int o=0,r=0;
    int ans=0;
    for (int i=0; i<n; i++)
    {
    	if (s[i]=='O') o++;
    	else r++;
    	if (o-m*r==0) ans=i;
    	else
    	{
            if (d[o-m*r]!=0) ans=max(ans,i-d[o-m*r]);
            else d[o-m*r]=i;
    	}
    }
    cout<<ans;
}

