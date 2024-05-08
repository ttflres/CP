#include <bits/stdc++.h>
#define sz(a) (int)a.size()
using namespace std;
int p[26][100007];
int m; 
string s;
bool check(int mid, int i)
{
    if (p[0][mid] - p[0][i - 1] >= m && p[1][mid] - p[1][i - 1] >= m&& p[2][mid] - p[2][i - 1] >= m && p[3][mid] - p[3][i - 1] >= m&& p[4][mid] - p[4][i - 1] >= m) return true;
    else return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> s >> m;
    int n = sz(s);
    s = " " + s;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < 26; ++j)
            p[j][i] = p[j][i - 1] + (s[i] - 'a' == j);

    int ans = n;
    for (int i = 1; i <= n; ++i)
    {
        int l = i, r = n, cur = INT_MAX;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (check(mid, i)) cur = mid, r = mid - 1;
            else l = mid + 1;
        }
        ans = min(ans, cur - i + 1);
    }

    if (p[0][n] < m || p[1][n] < m || p[2][n] < m || p[3][n] < m || p[4][n] < m) ans = -1;
    cout << ans;
    return 0;
}
