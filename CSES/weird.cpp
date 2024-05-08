#include<bits/stdc++.h>
using namespace std;
#define int long long

int n;

void go(int n)
{
	cout<<n<<" ";
	if (n==1) return;
	if (n%2==0) go(n/2);
	else go (3*n+1);
}

signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	go(n);
}

