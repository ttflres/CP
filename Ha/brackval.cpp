#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+7;

int v[maxn];
int n;

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int h=0;
	for (int i=1; i<=n; i++)
	{
		char c; cin >> c;
		if (c=='0') v[++h]=0;
		if (c=='1')
		{
			if (v[h]==0)
			{
				v[h-1]++;
				v[h-1]%=12345678910;
				h--;
			}
			else
			{
				v[h-1]+=v[h]*2;
				v[h-1]%=12345678910;
				h--;
			}
		}
	}
	cout<<v[0]%12345678910;
}

