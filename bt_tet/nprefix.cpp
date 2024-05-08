#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 7;
int scs(int n)
{
	int cnt=0;
	while (n!=0)
	{
		n/=10;
		cnt++;
	}
	return cnt;
}
int main() {
    int m, n;
    cin >> m >> n;
    int c=scs(m)*10;
    cout<<(n-m)/c + 1;
    
}

