/*#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define pii pair <int, int>
const int maxn = 1e5+7, mod=1e9+7;
int n, a, b, c, d;
signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	while (n--)
	{
		cin >> a >> b >> c >> d;
		if (b>=d) b-=d, d=0;
		else d-=b, b=0;
		int tmp=1, tmpp=1;
		for (int i=1; i<=b; i++) tmp*=10;
		for (int i=1; i<=d; i++) tmpp*=10; 
		//cout<<tmp<<" "<<tmpp<<endl;
		if (a*tmp<c*tmpp) cout<<"X < Y"<<endl;
		else if (a*tmp>c*tmpp) cout<<"X > Y"<<endl;
		else cout<< "X = Y"<<endl;
	}
}
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define pii pair <int, int>
const int maxn = 1e6+7, mod=1e9+7;
int n, a[maxn];
int pf[maxn], sf[maxn], tmp1, tmp2;
signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i=1; i<=n; i++) cin >> a[i];
	for (int i=1; i<=n; i++)
	{
		pf[i]=__gcd(pf[i-1], a[i]);
	}
	for (int i=n; i>=1; i--)
	{
		sf[i]=__gcd(sf[i+1], a[i]);
	}
	for (int i=1; i<=n; i++)
	{
		tmp1=max(tmp1, __gcd(pf[i-1], sf[i+1]));
	}
	cout<<tmp1;
}
#include <bits/stdc++.h>
using namespace std;
const int maxn=1005;
    int n,q;
int b[maxn],d[maxn][maxn];
bool check;
int solve(int val){
    int cur=0;
    int res=0;
    for(int i=1; i<=n; i++){
        check=false;
        for(int j=1; j<=b[i]; j++){
        if(d[i][j]==val){
    check=true;
        break;
}
    }
        if(check){
            cur++;
            res=max(res,cur);
        }else cur=0;
}
    return res;
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
cin>>n>>q;
for(int i=1; i<=n; i++){
        cin>>b[i];
for(int j=1; j<=b[i]; j++)
    cin>>d[i][j];
    }
for(int i=1; i<=q; i++){
    int val;
cin>>val;
cout<<solve(val)<<endl;
}
  return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define pii pair <int, int>
const int maxn = 1005, mod=1e9+7;
int n, m;
bool a[maxn][maxn];
int d[maxn][maxn];
const int dx [] = {-1, 0, 1, 0};
const int dy [] = {0, 1, 0, -1};
vector<int> r[maxn], c[maxn];
bool vl(int x, int y)
{
	return (1<=x&&x<=n&&1<=y&&y<=m);
}
signed main()
{
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) {
		cin >> a[i][j];
		if (a[i][j])
		{
			r[i].push_back(j);
			c[j].push_back(i);
		}
	}
	memset(d,-1,sizeof(d));
	d[1][1]=0;
	queue<pii> q;
	q.push({1,1}); 
	while (!q.empty())
	{
		int u=q.front().first, v=q.front().second;
		q.pop();
		if (u==n&&v==m)
		{
			cout<<d[u][v];
			return 0;
		}
		for (int i=0; i<4; i++)
		{
			int x=u+dx[i], y=v+dy[i];
			if (!vl(x,y)) continue;
			if (d[x][y]==-1)
			{
				d[x][y]=0;
				d[x][y]=d[u][v]+1;
				q.push({x,y});
			}
		}
		if (a[u][v]==1)
		{
			auto s1=lower_bound(r[u].begin(), r[u].end(), v)-r[u].begin()-1, e1=upper_bound(r[u].begin(), r[u].end(), v)-r[u].begin();
			if (e1==r[u].size()) e1=m;
			else e1=r[u][e1];
			if (s1<0) s1=1;
			else s1=r[u][s1];
			for (int i=s1; i<=e1; i++)
			{
				if (d[u][i]==-1)
				{
					d[u][i]=d[u][v]+1;
					q.push({u,i});
				}
			}
			auto s2=lower_bound(c[v].begin(), c[v].end(), u)-c[v].begin()-1, e2=upper_bound(c[v].begin(), c[v].end(), u)-c[v].begin();
			if (e2==c[v].size()) e2=n;
			else e2=c[v][e2];
			if (s2<0) s2=1;
			else s2=c[v][s2];
			for (int i=s2; i<=e2; i++)
			{
				if (d[i][v]==-1)
				{
					d[i][v]=d[u][v]+1;
					q.push({i,v});
				}
			}
		}
	}
}



