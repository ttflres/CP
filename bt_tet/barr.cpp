#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5+7;
int d[maxn]={0};
bool flag=true;
signed main(){
    int n;
	cin >> n;
	int ans=0;
	int a[n];
	for (int i = 0; i < n; i++) cin >> a[i];
	int i = 0;
	int j = -1;
	while (i < n){
		while (flag && j < n - 1){
			j++;
			d[a[j]]++;
			if(d[a[j]] > 2) flag = false;
		}
		if(!flag) ans += j - i;
		else ans += j - i + 1;
		if(d[a[i]] == 3) flag = true;
		d[a[i]]--;
		i++;
	}
	cout << ans;
}
