#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 7;
int n, a[maxn];
int cnt=0;
int cnp(int t)
{
    int l=0, h=n;
    while (l<h)
    {
        int mid=(l+h)/2;
        if (a[mid]<t) l=mid+1;
        else h=mid;
    }
    return l;
}
int main() {
    //freopen("baseball.in","r",stdin);
    //freopen("baseball.out","w",stdout);
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
        sort(a,a+n);
    for (int i=0; i<n; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            int d=a[j]-a[i];
            cnt+=cnp(a[j]+2*d+1)-cnp(a[j]+d);
        }
    }
    cout<<cnt;
    
}

