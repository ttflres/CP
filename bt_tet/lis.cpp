#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 7;
int main() {
    int n;
    cin >> n;
    vector<int>a;
    for (int i=0; i<n; i++)
    {
    	int x;
    	cin >> x;
    	auto it=lower_bound(a.begin(), a.end(), x);
    	if (it!=a.end()) *it=x;
    	else a.push_back(x);
    }
    cout<<a.size();
    
}

