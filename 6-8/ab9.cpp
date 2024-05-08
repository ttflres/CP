#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 7;

int n;
int arr[maxn];
string a, b;
bool check;
string tmp;
vector<string> v;
vector<int> l;

int to_int(string s)
{
    int ti=0;
    for (auto x:s) ti=ti*10+x-'0';
    return ti;
}

void in(int n)
{
    string ans="";
    bool flag1=true, flag0=true;
    for (int i=1; i<=n; i++)
    {
        if (arr[i]==1) ans+=a, flag1=false;
        else ans+=b, flag0=false;
    }
    if (!flag1&&!flag0)
    {
    int s=0;
    for (auto x:ans)
    {
        s+=x-'0';
    }
    if (s%9==0) v.push_back(ans);
    }


}
void sinh(int i, int n)
{
    for (int j=0; j<=1; j++)
    {
        arr[i]=j;
        if (i==n)
        {
            in(n);
        }
        else sinh(i+1, n);
    }
}
signed main() {
    cin >> a >> b;
    for (int i=2; i<=9; i++)
    {
       sinh(1, i);
    }
    for (auto x:v)
    {
        l.push_back(to_int(x));
    }
    cout<<*min_element(l.begin(), l.end());

}