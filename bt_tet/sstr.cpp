#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 7;
int main() {
    string s;
    cin >> s;
    string sstr;
    for (int i=0; i<s.size(); i++)
    {
    	sstr+=s[i];
    	if (s.size()%sstr.size()!=0) continue;
    	for (int j=sstr.size(); j<s.size(); j+=sstr.size())
    		{
    			if (s.substr(j,sstr.size())!=sstr)
    				{
    					
    				}
    		}
    		cout<<s.size()/sstr.size()<<sstr;
    		return 0;
    }
    
}

