#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 7;
long long power_modulo(long long a, long long b, long long M) 
{
    if (b == 0)
        return 1LL;

    long long half = power_modulo(a, b / 2, M) % M;

    if (b & 1)
        return (((half * half) % M) * (a % M)) % M;
    else
        return (half * half) % M;
}
int main() {
    long long a, b;
    cin >> a >> b;
    cout<<power_modulo(a,b,10);
    
}

