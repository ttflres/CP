#include<bits/stdc++.h>
using namespace std;
#define ll long long

int n, m;
int a[51];
string s[51];
int cnt=0, ans=51;

void in()
{
	string t1, t2;
    for (int i=1; i<=n; i++) 
    {
    	if (a[i]==1) t1+=s[i];
    	else if (a[i]==2) t2+=s[i];
	}
	if (t1==t2&&t1!="") 
	{
		cnt++;
		int c=t1.size();
		ans=min(ans, c);
//		cout<<t1<<" "<<t2<<endl;
	}
}
void sinh(int i)
{
    for (int j=0; j<=2; j++)
    {
        a[i]=j;
        if (i==n) in();
        else sinh(i+1);
    }
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	freopen("CODE.INP", "r", stdin);
	freopen("CODE.OUT", "w", stdout);
    cin >> n >> m;
    for (int i=1; i<=n; i++)
    {
    	cin >> s[i];
	}
    sinh(1);
    if (cnt==0) cout<<-1;
    else cout<<ans;
}
    
