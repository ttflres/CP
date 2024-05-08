#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair <int, int>
const int maxn = 1e5+7;
int n;
int cnt=0;
signed main()
{
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i=1; i*i*i<=n; i++)
    {
        for (int j=i; j<=sqrt(n/i); j++)
        {
            if (i==j) cnt+=(n/(i*j)-j)*3+1;
            else cnt+=(n/(i*j)-j)*6+3;
        }
    }
    cout<<cnt;
}
