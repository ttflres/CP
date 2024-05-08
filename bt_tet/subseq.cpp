#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 7;
int n, a[maxn];
void input()
{
	cin >> n;
	for (int i=0; i<n; i++) cin >> a[i];
}
void kdno()
{
    bool flag=true;
    int sum=0;
    for (int i=0; i<n; i++)
    {
        if (a[i]>=0)
        {
            flag=false;
            sum+=a[i];
        }
    }
    if (flag) sum=*max_element(a,a+n);
    cout<<sum<<" ";
}
void kdn()
{
	int best = INT_MIN;
    int sum = 0;
    for (int i = 0; i < n; i ++) {
    sum = max(a[i], sum + a[i]);
    best = max(sum, best);
    }
    cout << best;
}
signed main() {
    int t;
    cin >> t;
    while (t--)
    {
    input();
    kdno();
    kdn();
    cout<<endl;
    }
   
    
}

