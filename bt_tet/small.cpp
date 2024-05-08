#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 7;
int main() {
    int n;
    cin >> n;
    int a[n];
    map<int,int> mp;
    for (int i=0; i<n; i++)
    {
    	cin >> a[i];
    	mp[a[i]]++;
    }
    int sum = 0;
        for(auto it = mp.begin();it != mp.end();it++)
        {
            int temp = it->second;
            it->second = sum;
            sum += temp;
        }
    for (int i=0; i<n; i++)
    {
    	cout<<mp[a[i]]<<" ";
    }

    
}

