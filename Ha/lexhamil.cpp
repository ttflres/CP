#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=100;

int t;
int n, m;
string s;
vector<int> g[maxn];

void dick(int x, int y)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i=1; i<=n; i++) l[i]=maxn;
    l[x]=0;
    pq.push({0, x});
    int i,j,c;
    while (!pq.empty())
    {
        i=pq.top().second;
        c=pq.top().first;
        pq.pop();
        if (l[i]!=c) continue;
        if (i==y) break;
        for (auto x:g[i])
        {
            j=x.second;
            c=x.first;
            if (l[j]>l[i]+c)
            {
                l[j]=l[i]+c;
                pq.push({l[j], j});
                tr[j]=i;
            }
        }
    }

}

void solve()
{
    cin >> n >> m;
    cin >> s;
    for (int i=1; i<=m; i++)
    {

    }

}

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   cin >> t;
   while (t--) solve();

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