#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+7;

int n, m;
string s[105][105];
int a[105][105];

int to_int(string s)
{
    int a=0;
    for (int i=0; i<s.size(); i++)
    {
        a=a*10+(s[i]-'0');
    } 
    return a;
}

int to_col(string s)
{
    int a=0;
    for (int i=0; i<s.size(); i++)
    {
        a=a*26+(s[i]-'A'+1);
    }
    return a;
}

unsigned int calc(int i, int j) {
    string k = s[i][j];
    vector<string> v;
    string t;
    if (k[0]!='=') return a[i][j];
    for(int i=1; i<k.size(); i++) {
        if ((k[i]>= 'A' && k[i]<= 'Z') || (k[i]>= '0' && k[i]<= '9')) t = t + k[i];
        else {
            v.push_back(t);
            t="";
        }
        if (i == k.size()-1) v.push_back(t);
    }
    unsigned int cur = 0;
    for(string x : v) {
        string q, r;
        for(int i = 0 ; i < x.size(); i++) {
            if (x[i] >= 'A' && x[i] <= 'Z') q+=x[i];
            else r+=x[i];
        }
        int u = to_col(q), v = to_int(r);
        if (a[v][u] == 0)cur += calc(v,u);
        else cur += a[v][u];
    }
    return cur;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> m;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            cin >> s[i][j];
            if (s[i][j][0]!='=') a[i][j]=to_int(s[i][j]);
        }
    }
     for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            a[i][j] = calc(i,j);
        }
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}
