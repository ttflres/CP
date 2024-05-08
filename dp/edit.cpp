#include<bits/stdc++.h>
using namespace std;
const int mn=5005;
int f[mn][mn];
int main()
{
    string a,b;
    cin >> a >> b;
    for (int i=0; i<a.size()+1; i++) f[i][0]=i;
    for (int i=0; i<b.size()+1; i++) f[0][i]=i;
    for (int i=1; i<a.size()+1; i++)
    {
        for (int j=1; j<b.size()+1; j++)
        {
            f[i][j]=INT_MAX;
            f[i][j]=min({f[i-1][j-1]+(a[i-1]!=b[j-1]), f[i-1][j]+1, f[i][j-1]+1});
        }
    }
    cout<<f[a.size()][b.size()];
}