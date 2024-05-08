#pragma GCC optimize("Os")
#include<bits/stdc++.h>

using namespace std;

#define int long long
#define pii pair<int, int>
const int maxn = 1e5 + 7;

int n, m, A, B, C, D;
vector<pii> g[maxn];
int l[maxn], tr[maxn];
map<pii, int> mp;
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
        	if ((mp.find({i, j})!=mp.end()||mp.find({j,i})!=mp.end())&&(mp[{i,j}]==1||mp[{j, i}]==1)) c=0;
        	else c=x.first;
            if (l[j]>l[i]+c)
            {
                l[j]=l[i]+c;
                pq.push({l[j], j});
                tr[j]=i;
            }
        }
    }

}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("tunnel.inp", "r", stdin);
    freopen("tunnel.out", "w", stdout);
    cin >> n >> m;
    cin >> A >> B >> C >> D;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({c,b});
        g[b].push_back({c,a});
    }
    dick(A,B);
    stack<int>st;
    st.push(B);
    int i=B;
    while (i!=A)
    {
        i=tr[i];
        st.push(i);
    }
    int crr=st.top();
    st.pop();
//    cout<<crr<<endl;
    while (st.size())
    {
        mp[{st.top(), crr}]=1;
        mp[{crr, st.top()}]=1;
        crr=st.top();
        st.pop();
//        cout<<crr<<endl;
    }
    dick(C, D);
    cout<<l[D];
}
