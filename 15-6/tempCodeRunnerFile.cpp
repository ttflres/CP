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
	void run()
	{
	int m1 = n / 2, m2 = n - m1;
    int arr1[m1], arr2[m2];
    for (int i = 0; i < m1; i++) cin >> arr1[i];
    for (int i = 0; i < m2; i++) cin >> arr2[i];

    vector<int> sum1, sum2;
    for (int i = 0; i < (1 << m1); i++) { 
        int cur = 0;
        for (int j = 0; j < m1; j++)
            if (i & (1 << j))
                cur += arr1[j];
        sum1.push_back(cur);
    }
    for (int i = 0; i < (1 << m2); i++) { 
        int cur = 0;
        for (int j = 0; j < m2; j++)
            if (i & (1 << j))
                cur += arr2[j];
        sum2.push_back(cur);
    }
	sort(sum1.begin(), sum1.end());
	sort(sum2.begin(), sum2.end());
	int ans=0;
	for (auto x:sum1)
	{
		int tmp=m-x%m-1;
		// cout<<x<<" "<<m-x%m-1<<endl;
		int l=0, r=sum2.size()-1, anss=0;
		while (l<=r)
		{
			int mid=(l+r)>>1;
			if (sum2[mid]%m<=tmp)
			{
				anss=sum2[mid]%m;
				l=mid+1;
			} else r=mid-1;
		}
		// cout<<anss<<endl;
		if (anss+tmp==m) anss=-tmp;
		ans=max(ans, anss+tmp);
	}
	cout<<ans;
}
}

signed main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	// if (n<=20) sub1::run();
	 sub2::run();
}
