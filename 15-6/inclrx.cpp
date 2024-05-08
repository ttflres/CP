// #include<bits/stdc++.h>
// using namespace std;
// #define int long long
// const int maxn=1e7+7;

// bool prime[maxn];
// void sieve()
// {
// 	for (int i=1; i<=maxn; i++) prime[i]=true;
// 	prime[0]=false, prime[1]=false;
// 	for (int i=2; i*i<=maxn; i++)
// 	{
// 		if (prime[i])
// 		for (int j=i*i; j<=maxn; j+=i)
// 		{
// 			if (prime[j]) prime[j]=false;
// 		}
// 	}
// }

// int n, k;

// signed main()
// {
// 	ios_base::sync_with_stdio(false); cin.tie(NULL);
// 	#ifndef ONLINE_JUDGE
// 	freopen("nhapinput.inp", "r", stdin);
// 	freopen("nhapoutput.out", "w", stdout);
// 	#endif 
// 	sieve();
// 	cin >> n >> k;
// 	int ans=0;
// 	for (int i=1; i<=n; i++)
// 	{
// 		int cnt=0, r=0;
// 		while (r<=n&&cnt<k) cnt+=prime[r++];
// 		ans+=r-n+1;
// 		if (prime[i]) cnt--;
// 	}
// 	cout<<ans;
// }
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+7;



signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	#ifndef ONLINE_JUDGE
	freopen("nhapinput.inp", "r", stdin);
	freopen("nhapoutput.out", "w", stdout);
	#endif 
	cout<<"Dit me du tuyen";
}
