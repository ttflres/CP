#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 7;
int main() {
    int n;
    cin >> n;
    int a[3];
    int cnt=0;
    for (int i=0; i<3; i++) cin >> a[i];
        sort(a,a+3);
    for (int i=0; i<3; i++)
    {
        if (n>=a[i])
        {
            n-=a[i];
            cnt++;
        }
    }
    cout<<cnt;
}

