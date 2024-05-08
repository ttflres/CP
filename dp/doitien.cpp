#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 7;
bool isPrime[N];
void sieve(int N) {
    for(int i = 0; i <= N;++i) {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i * i <= N; ++i) {
         if(isPrime[i] == true) {
             for(int j = i * i; j <= N; j += i)
                 isPrime[j] = false;
        }
    }
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	sieve(N);
	int n;
	cin >> n;
	int a[n+1], b[n+1];
	b[0]=0;
	int ans=0;
	for (int i=1; i<=n; i++){
		cin >> a[i];
		b[i]=b[i-1]+a[i];
	}
	for (int i=1; i<=n; i++)
	{
		if (isPrime[i]==true)
		{
			for (int j=i+1; j<=n; j++)
			{
				if (isPrime[j]==true)
				{
					ans=max(b[j]-b[i-1],ans);
					cout<<i<<" "<<j<<endl;
				}
			}
		}
	}
	cout<<ans;
}



