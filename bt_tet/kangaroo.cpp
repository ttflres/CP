#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 7;
int main() {
    int a, b, c;
    cin >> a >> b >> c;
    cout<<max(abs(a-b)-1, abs(c-b)-1);
    
}

