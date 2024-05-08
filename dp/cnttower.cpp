#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e9 + 7;
const int md=1e6+6;
int f[md][3];
void init()
{
	f[1][1]=f[1][2]=1;
	for (int i=2; i<md; i++)
	{
		f[i][1]=(f[i-1][1]*4%maxn+f[i-1][2])%maxn;
		f[i][2]=(f[i-1][1]+f[i-1][2]*2%maxn)%maxn;
	}
}
signed main() {
	init();
    int t;
    cin >> t;
    while (t--)
    {
    	int n;
    	cin >> n;
    	cout<<(f[n][1]+f[n][2])%maxn<<endl;
    }
    
}

