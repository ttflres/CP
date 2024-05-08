#include<bits/stdc++.h>
using namespace std;
#define int long long

int a, b;

signed main()
{
	freopen("DIENPHEPTINH.INP", "r", stdin);
	freopen("DIENPHEPTINH.OUT", "w", stdout);
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> a >> b;
	if (a+a+a==b)
	{
		cout<<"+"<<endl<<"+";
	}
	else if (a+a-a==b)
	{
		cout<<"+"<<endl<<"-";
	}
	else if (a+a*a==b)
	{
		cout<<"+"<<endl<<"*";
	}
	else if (a-a-a==b)
	{
		cout<<"-"<<endl<<"-";
	}
	else if (a-a+a==b)
	{
		cout<<"-"<<endl<<"+";
	}
	else if (a-a*a==b)
	{
		cout<<"-"<<endl<<"*";
	}
	else if (a*a*a==b)
	{
		cout<<"*"<<endl<<"*";
	}
	else if (a*a+a==b)
	{
		cout<<"*"<<endl<<"+";
	}
	else if (a*a-a==b)
	{
		cout<<"*"<<endl<<"-";
	}
}

