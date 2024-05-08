#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 7;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	string res="";
	for (int i=1; i<s.size(); i++)
	{
		res+=s[i];
		res+=res[0];
		res.erase(res.begin());
		cout<<res<<endl;
	}
}



