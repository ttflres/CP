#include<bits/stdc++.h>
#define int long long
#define maxn 100000

using namespace std;

int n,p[maxn+1],res=0,m;

void sieve(){
    for (int i=1;i<=maxn;i++)
        p[i]=i;
    for (int i=2;i*i<=maxn;i++)
        if (p[i]==i)
            for (int j=i*i;j<=maxn;j+=i)
                p[j]=i;
}

void xuli(int x){
    int t=1,sl=1,s=x;
    vector<int> v;
    while (x>1){
        v.push_back(p[x]);
        x/=p[x];
    }
    sort(v.begin(),v.end());
    for (int i=0;i<v.size();i++){
        if (i==v.size()-1){
            if (sl%2==1) t*=v[i];
            break;
        }
        if (v[i]!=v[i+1]){
            if (sl%2==1) t*=v[i];
            sl=1;
        }
        else sl++;
    }
    //cout<<s<<" "<<t<<" "<<cur<<endl;
    //cout<<t<<" ";
    //cout<<res<<endl;
    res+=sqrt(m/t);
    //cout<<res<<" "<<t<<endl;
}

void readData(){
    cin>>n;
    m=n;
}

void solve(){
    for (int i=1;i<=n;i++)
        xuli(i);
    cout<<res;
}

signed main(){
    sieve();
    readData();
    solve();
    return 0;
}
