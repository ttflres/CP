#include <bits/stdc++.h>
using namespace std;

long long n, a[107][107][107], dist[107][107][107];
bool visited[107][107][107];
struct NODE{
    long long w, x, y, z;
};
struct cmp{
    bool operator() (NODE a, NODE b){
        return a.w > b.w;
    }
};
struct VERTEX{
    int x, y, z;
};
vector<VERTEX> adj[107][107][107];

void dijkstra(int x, int y, int z){
    memset(dist, 0x3f, sizeof dist);
    memset(visited, false, sizeof visited);

    dist[x][y][z] = 0;
    priority_queue<NODE, vector<NODE>, cmp> pq;
    pq.push({dist[x][y][z], x, y, z});

    while(!pq.empty()){
        NODE u = pq.top();
        pq.pop();

        if(visited[u.x][u.y][u.z]) continue;
        visited[u.x][u.y][u.z] = true;

        for(int i = 0; i < (int) adj[u.x][u.y][u.z].size(); i++){
            VERTEX v = adj[u.x][u.y][u.z][i];
            if(dist[v.x][v.y][v.z] > dist[u.x][u.y][u.z] + a[v.x][v.y][v.z]){
                dist[v.x][v.y][v.z] = dist[u.x][u.y][u.z] + a[v.x][v.y][v.z];
                pq.push({dist[v.x][v.y][v.z], v.x, v.y, v.z});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                cin >> a[i][j][k];
                if(i > 1) adj[i][j][k].push_back({i - 1, j, k});
                if(j > 1) adj[i][j][k].push_back({i, j - 1, k});
                if(k > 1) adj[i][j][k].push_back({i, j, k - 1});

                if(i < n) adj[i][j][k].push_back({i + 1, j, k});
                if(j < n) adj[i][j][k].push_back({i, j + 1, k});
                if(k < n) adj[i][j][k].push_back({i, j, k + 1});
            }
        }
    }

    dijkstra(1, 1, 1);
    cout << dist[n][n][n] << "\n";
}
