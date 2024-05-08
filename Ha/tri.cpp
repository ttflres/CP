#include<bits/stdc++.h>
using namespace std;
#define int long long

int n, res;
char a[105][105];
map<char, pair<int, int>>mp;

signed main()
{
	freopen("tri.inp", "r", stdin);
	freopen("tri.out", "w", stdout);
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	set<char>st;
	for(int i = 1;i <= n;i++){
		for(int j =  1;j <= n;j++){
			cin >> a[i][j];
			if(a[i][j] != '.') mp[a[i][j]] = {i,j};
			st.insert(a[i][j]);
		}
	}
	set<pair<pair<char,char>,char>>q;
	for(char x = 'A'; x <= 'Z';x++){
		for(char y =x+1;y <= 'Z';y++){
			if(x == y||!st.count(x) || !st.count(y)) continue;
			char w[4];
			w[0] = x;
			w[1] = y;
			int a1 = mp[y].second - mp[x].second;
			int b1 = mp[x].first - mp[y].first;
			int c1 = (mp[x].first*mp[y].second-mp[y].first *mp[x].second);
			for(auto it:mp){
				if(it.first != x && it.first != y && a1*mp[it.first].first + b1*mp[it.first].second == c1){
					w[2] = it.first;
					sort(w,w+3);
					q.insert({{w[0],w[1]},w[2]});
				}
				w[0] = x;
				w[1] = y;
			}
		}
	}
	cout << q.size();
}

