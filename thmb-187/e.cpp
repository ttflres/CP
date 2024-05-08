#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+7;

int n;
int pfs;
map<int, int> cnt;

signed main()
{
   ios_base::sync_with_stdio(false); cin.tie(NULL);
   cin >> n;
   cnt[0] = 1;
   long long ans = 0;
   for (int i = 1; i <= n; i++) {
    char c;
    cin >> c;
    pfs = pfs ^ (1 << (c - 'a'));
    ans += cnt[pfs];
    for (int j = 0; j < 26; ++j) {
        ans += cnt[pfs ^ (1 << j)];
    }
    cnt[pfs]++;
   }
   cout << ans;

   return 0;
}