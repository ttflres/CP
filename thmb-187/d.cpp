#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e5+7;

int n;
int num=0;
int cnt[61];

int pw(int a, int b)
{
    if (b==0) return 1;
    int tt=pow(a, b/2);
    tt*=tt;
    if (b&1) return tt*a;
    return tt;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n;
    while (n--)
    {
        string s; cin >> s;
        if (s=="ADD")
        {
            int a; cin >> a;
            for (int i=0; i<61; i++)
            {
                if (a>>i&1) cnt[i]++;
            }
            num++;
        }
        if (s=="DEL")
        {
            int a; cin >> a;
            for (int i=0; i<61; i++)
            {
                if (a>>i&1) cnt[i]--;
            }
            num--;
        }
        if (s=="OR")
        {
            int ans=0;
            for (int i=0; i<61; i++)
            {
                if (cnt[i]>0) ans+=pw(2, i);
            }
            if (num)
            cout<<ans<<endl;
            else cout<<0<<endl;
        }
        if (s=="AND")
        {
            int ans=0;
            for (int i=0; i<61; i++)
            {
                if (cnt[i]==num) ans+=pw(2, i);
            }
            if (num) cout<<ans<<endl;
            else cout<<0<<endl;
        }
        if (s=="XOR")
        {
            int ans=0;
            for (int i=0; i<61; i++)
            {
                if (cnt[i]&1) ans+=pw(2, i);
            }
            if (num) cout<<ans<<endl;
            else cout<<0<<endl;
        }
    }
}