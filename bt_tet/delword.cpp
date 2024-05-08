#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 7;
int main() {
    int t;
    cin >> t;
    while (t--)
    {
    	string s,d;
    	cin >> s >> d;
    	while (1)
    	{
    		if (s.find(d)==-1) break;
    		s.erase(s.find(d), d.size());
    	}
    	cout<<s<<endl;
    }
    
}

