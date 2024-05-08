#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define int long long
#define ull unsigned long long
#define vec vector
#define str string
#define db double
#define fl float
#define all(x) x.begin(),x.end()
#define fi first
#define se second
#define ii pair<int, int> 
#define endl '\n'
using namespace std;
int i,j;
const int llmax = LONG_LONG_MAX;
const int llmin = LONG_LONG_MIN;
const int maxN = 1e9+1;
int n;
int a[1007][1007];
void readData(){
    cin>>n;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cin>>a[i][j];
        }
    }
}

void sol(){
    int ans=0;
    vec<ii> min;
    vec<ii> temp;
    int tmp;
    // min
    for(tmp=1;tmp<=n;tmp++){
        int mans=maxN;
        i=1;j=tmp;
        while(j>=1){
            if(a[i][j]<mans){
                temp.clear();
                temp.push_back({i,j});
                mans=a[i][j];
            }
            else if(a[i][j]==mans){
                temp.push_back({i,j});
            }
            i++; j--;
        }
        for(auto&it:temp){
            min.push_back(it);
        }
        temp.clear();
    }
    for(tmp=2;tmp<=n;tmp++){
        int mans=maxN;
        i=tmp;
        j=n;
        while(i<=n){
            if(a[i][j]<mans){
                mans=a[i][j];
                temp.clear();
                temp.push_back({i,j});
            }
            else if(a[i][j]==mans){
                temp.push_back({i,j});
            }
            i++; j--;
        }
        for(auto&it:temp){
            min.push_back(it);
        }
        temp.clear();
    }
    
    // for(auto&it:min){
        // cout<<it.fi<<" "<<it.se<<endl;
    // }

        
    // ket qua
    for(auto&it:min){
        bool check=1;   
        int val=    a[it.fi][it.se];
        i=it.fi-1;j=it.se-1;
        while(i>=1&&j>=1){
            if(a[i][j]>val){
                check=0;
                break;
            }
            i--; j--;
        }
        i=it.fi+1;j=it.se+1;
        while(i<=n&&j<=n){
            if(a[i][j]>val){
                check=0;
                break;
            }
            i++;j++;
        }
        if(check){
            ans+=val;
            // cout<<it.fi<<" "<<it.se<<endl;
        }
    }
    cout<<(ans==0? 0: ans);
    
}

signed main() {
    IOS
    readData();
    sol();
    return 0;
}
