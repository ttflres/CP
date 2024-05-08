#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=3e4+7;

struct point{
    int x, y1, y2, type;
    bool operator < (const point& other) const {
        return x < other.x;
    }
};

vector<point> st;
int n;

struct ST{
    vector<pair<int, int>> s;
    void update(int id, int l, int r, int u, int v, int val) {
        if (l > v || r < u) return;
        if (l >= u && r <= v) {
            s[id].second += val;
            if (s[id].second != 0) s[id].first = r - l + 1;
            else if (l != r) s[id].first = s[id * 2].first + s[id * 2 + 1].first;
            else s[id].first = 0;
            return;
        }
        int m = (l + r) >> 1;
        update(id * 2, l, m, u, v, val);
        update(id * 2 + 1, m + 1, r, u, v, val);
        if (s[id].second != 0) s[id].first = r - l + 1;
        else s[id].first = s[id * 2].first + s[id * 2 + 1].first;
    }
};



signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   cin >> n;
   for (int i=1; i<=n; i++)
   {
       int x1, y1, x2, y2;
       cin >> x1 >> y1 >> x2 >> y2;
       st.push_back({x1, y1, y2, 1});
       st.push_back({x2, y1, y2, -1});
   }   sort(st.begin(), st.end());
   ST segtree(maxn);
   int ans=0;
   for (int i=0; i<st.size()-1; i++)
   {
       segtree.update(1, 0, maxn, st[i].y1, st[i].y2-1, st[i].type);
       ans+=(st[i+1].x-st[i].x)*segtree.s[1].first;
   }
   cout<<ans;
}
/*
==================================================+
INPUT
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/