#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 7;
int main() {
    int n, m, p, cnt=0;
    cin >> n >> m >> p;
    vector<pair<int, int> > v;
    for (int i=0; i<n; i++)
    {
    	int a, b;
    	cin >> a >> b;
    	v.push_back({a,b});
    }
    for (int i=0; i<n; i++)
    {
    	v.push_back({v[i].first, v[i].second});
    }

    	for (int i=0; i<2*n; i++)
    {
    	if (v[i].second==p)
    	{
    		p=v[i].first;
    		cnt++;
    	}
    }
    if (cnt==0) cout<<-1;
    else cout<<cnt;
}

