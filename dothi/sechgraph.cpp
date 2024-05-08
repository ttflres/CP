#include<bits/stdc++.h>
using namespace std;
#define int long long

const int inf=(int) 1e18;
const int maxn = 2e5+7;

bool mini(int& a,int b){
    if(b<a){
        a=b;
        return true;
    }return false;
}

int n,m,i,j;
vector<pair<int, int>> g[2][maxn];
int dist[2][maxn];

void dijkstra(int tt){
    for(int i=1;i<=n;i++){
        dist[tt][i]=inf;
    }
    dist[tt][1]=0;
    priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int> > > pq;
    pq.push({0,1});
    while(pq.size()){
        int u=pq.top().second;
        int w=pq.top().first;
        pq.pop();
        if(w != dist[tt][u] ) continue;
        for(auto k: g[tt][u]){
            if(mini(dist[tt][k.first],dist[tt][u]+k.second)){
                pq.push(make_pair(dist[tt][k.first],k.first));
            }
        }
    }


}



signed main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t=1;
	cin>>n>>m;
    for(i=1;i<=m;i++){
        int u,v,c;
        cin>>u>>v>>c;
        g[0][u].push_back({v,c});
        g[1][v].push_back({u,c});
    }
    dijkstra(0);
    dijkstra(1);
    for(i=2;i<=n;i++){
        int ans=dist[0][i]+dist[1][i];
        if(ans>=inf){
            cout<<-1<<endl;
        }else{
            cout<<ans<<endl;
        }

    }
}
