#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+7;

int n, m, a[maxn];

namespace sub1
{
	int b[21], ans=0;
	void in()
	{
		int s=0;
		for (int i=1; i<=n; i++)
		{
			if (b[i]==1) s+=a[i];
		}
		ans=max(ans, s%m);
	}
	void sinh(int i)
	{
		for (int j=0; j<=1; j++)
		{
			b[i]=j;
			if (i==n) in();
			else sinh(i+1);
		}
	}
	void run()
	{
		for (int i=1; i<=n; i++) cin >> a[i];
		sinh(1);
		cout<<ans;
	}
}

namespace sub2
{
	int m1, m2, arr1[maxn], arr2[maxn];
	vector<int> sum1, sum2;
	int ans=0;
	void run()
	{
	m1 = n / 2, m2 = n - m1;
    for (int i = 0; i < m1; i++) cin >> arr1[i];
    for (int i = 0; i < m2; i++) cin >> arr2[i];
    for (int i = 0; i < (1 << m1); i++) { 
        int cur = 0;
        for (int j = 0; j < m1; j++)
            if (i & (1 << j))
                cur += arr1[j];
        sum1.push_back(cur%m);
    }
    for (int i = 0; i < (1 << m2); i++) { 
        int cur = 0;
        for (int j = 0; j < m2; j++)
            if (i & (1 << j))
                cur += arr2[j];
        sum2.push_back(cur%m);
    }
	sort(sum1.begin(), sum1.end());
	sort(sum2.begin(), sum2.end());
	int ans=0;
	for (auto x:sum2)
	{
		auto it=lower_bound(sum1.begin(), sum1.end(), m-x)-sum1.begin();
		ans=max({ans, (x+sum1[it-1])%m, (x+sum1.back())%m});
	}
	cout<<ans;
}
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	if (n<=20) sub1::run();
	else sub2::run();
}
