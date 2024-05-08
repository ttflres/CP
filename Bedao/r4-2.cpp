// WA 24/50
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5;
string a, b;
char A='A', B='B';
vector<int>aa, ab;
int ans;
signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a >> b;
	if (a.size()!=b.size()) cout<<-1;
	else
	{
		for (int i=1; i<a.size(); i++)
	{
		if (a[i]!=a[0]) a[i]=B;
		else a[i]=A;
	}
	a[0]=A;
	for (int i=1; i<b.size(); i++)
	{
		if (b[i]!=b[0]) b[i]=B;
		else b[i]=A;
	}
	b[0]=A;
	for (int i=0; i<a.size(); i++)
	{
		if (a[i]=='A') aa.push_back(i);
	}
	for (int i=0; i<b.size(); i++)
	{
		if (b[i]=='A') ab.push_back(i);
	}
	if (aa.size()!=ab.size()) cout<<-1;
	sort(aa.begin(), aa.end()); sort(ab.begin(), ab.end());
	for (int i=0; i<aa.size(); i++) ans+=abs(aa[i]-ab[i]);
	cout<<ans;
	}

}
