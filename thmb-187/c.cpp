#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+7;

int q, n, m;

int findMEX(int N, int K)
{
    int lastBit = max(round(log2(N + 1)),round(log2(K)));
    int X = 0;
    for (int i = lastBit; i >= 0; i--) {
        if ((K >> i & 1) == ((N + 1) >> i & 1)) continue;
        else if ((K >> i & 1) == 0) X = X | (1 << i);
        else break;
    }
    return X;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> q;
    while (q--)
    {
        cin >> n >> m;
        cout<<findMEX(m,n)<<endl;
    }
}