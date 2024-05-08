#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int n, m, a, b, c;
long long dis[100005];
vector <pair <int, int> > v[100005];
int tr[100005];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c;
        v[a].push_back({b, c});
    }
    memset(dis, 0x3F, sizeof(dis));
    dis[1] = 0;
    priority_queue <pair <long long, int>, vector<pair<long long, int> >, greater<pair<long long, int> > > pq;
    pq.push({0, 1});
    while (!pq.empty()){
        auto now = pq.top();
        pq.pop();
        if (now.first > dis[now.second]) continue;
        for (auto i:v[now.second]){
            if (dis[i.first] > dis[now.second] + i.second){
                dis[i.first] = dis[now.second] + i.second;
                pq.push({dis[i.first], i.first});
                tr[i.first]=now
            }
        }
    }

}