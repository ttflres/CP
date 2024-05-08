#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=505;

int n, d;
int c[maxn][maxn], dis[maxn][maxn];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> d;
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=n; j++)
        {
            cin >> c[i][j];
            dis[i][j]=c[i][j];
        }
    }
    int ans=1e18;
    for (int k=1; k<=n; k++) {
    for (int i=1; i<k; i++)
        for (int j=1; j<i; j++) 
            ans=min(ans, dis[i][j]+c[i][k]+c[j][k]); 
            for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
            {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
    }
    if (d-ans<0) 
    {
        cout<<-1;
        return 0;
    }
    cout<<d-ans;
}
