#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=55;

int n, m, a[maxn][maxn], c[maxn*maxn][maxn*maxn];
int dx[]={0, 1, 0, -1};
int dy[]={1, 0, -1, 0};
int ans;
bool flag=true;

string csl(string a, string b)
{
    int     du  = 0;
    int     mid = 0;
    string  res = "";
    a.insert(0ll, max(0ll, (int) (b.length() - a.length())), '0');
    b.insert(0ll, max(0ll, (int) (a.length() - b.length())), '0');
    for (int i = a.length()-1; i >= 0; --i)
    {
        mid = ((int) a[i] - 48) + ((int) b[i] - 48) + du;
        du  = mid / 10;
        res = (char) (mid % 10 + 48) + res;
    }
    if (du > 0) res = "1" + res;
    return res;
}

string nsb(string a, int b, int l)
{
    string  res = "";
    int     mid = 0;
    int     du  = 0;
    for (int i = a.length() - 1; i >= 0; --i)
    {
        mid     = ((int) a[i] - 48) * b + du;
        du  = mid / 10;
        res = (char) (mid % 10 + 48) + res;
    }
    if (du > 0)
    {
        string  k = to_string(du);
        res = k + res;
    }
    res.insert(res.length(), l, '0');
    return res;
}

string nsl(string a, string b)
{
    string  res = "";
    for (int i = b.length() - 1; i >= 0; --i)
    {
        string  t = nsb(a, (int) b[i] - 48, b.length() - i - 1);
        res     = csl(res, t);
    }
    return res;
}

void solve()
{
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            cin >> a[i][j];
        }
    }
    ans=0;
    memset(c, 0, sizeof(c));
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            if (a[i][j]==-1) continue;
            int s=(i-1)*m+j;
            for (int h=0; h<4; h++)
            {
                int u=i+dx[h], v=j+dy[h];
                if (u>0&&u<=n&&v>0&&v<=m) c[s][(u-1)*m+v]=1;
            }
            c[s][m*n+1]=a[i][j];
        }
    }
    for (int i=1; i<=m*n; i++)
    {
        bool ok=false;
        for (int j=1; j<=m*n; j++)
            if (c[i][j])
            {
                ok=true;
                for (int k=i+1;k<=n*m;k++)
                    if (c[k][j]) 
                    {
                        for (int j=1;j<=n*m+1;j++)
                            c[k][j]=(c[k][j]+c[i][j])%2;
                    }
                break;
            }
        if (!ok)
        {
            if (c[i][m*n+1]==0) ans++;
            else flag=false;
        }
    }
    if (!flag) cout<<0<<"\n";
    else{
        string res="1";
        for (int i=1;i<=ans;i++)
            res=nsl(res,"2");
        cout<<res<<"\n";
    }
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("nhapinput.inp", "r", stdin);
    freopen("nhapoutput.out", "w", stdout);
    #endif 
    while (cin >> n >> m)
    {
        if (n==0&&m==0) return 0;
        solve();
    }
}
