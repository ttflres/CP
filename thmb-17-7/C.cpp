    #include<bits/stdc++.h>
    using namespace std;
    #define int long long
    const int maxn=2e5+7;

    int n, q;
    int a[maxn], b[maxn], t[maxn];
    int d[maxn], s=0;
    int x=0;

    signed main()
    {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        cin >> n >> q;
        for (int i=1; i<=n; i++)
        {
            cin >> t[i];
            if (t[i]==0) x=i;
        }
        for (int i=1; i<=q; i++)
        {
            int type, j; cin >> type;
            if (type==1)
            {
                cin >> a[i] >> b[i];
                if (t[a[i]]==1&&t[b[i]]==2)
                {
                    d[b[i]]++;
                    d[x]++;
                }
                else if (t[a[i]]==2&&t[b[i]]==1)
                {
                    s++;
                    d[x]++;
                } else d[b[i]]++;
            }
            else if (type==2)
            {
                cin >> b[i] >> j;
                if (t[b[i]]==1&&t[a[j]]==2)
                {
                    s--;
                } else d[b[i]]--;
            }
            else
            {
                cin >> a[i];
                if (t[a[i]]==1) cout<<d[a[i]]+s<<endl;
                else cout<<d[a[i]]<<endl;
            }
        }
    }
