#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin>>n;
    vector<bool> sang(1000003,1);
    sang[0]=true;
    sang[1]=true;
    for(int i=2;i*i<=1000001;i++){
        if(sang[i]==true){
            for(int j=i*i;j<=1000001;j+=i){
                sang[j]=false;
            }
        }
    }
    int temp;
    while(n--){
        cin>>temp;
        if(sang[temp]||sang[temp-1]||sang[temp+1]){
            cout<<1<<endl;
        }
        else cout<<0<<endl;
    }
    return 0;
}
