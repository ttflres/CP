#include<bits/stdc++.h>
#define el '\n'
#define int long long
using namespace std ;

const int MN = 5e5 + 10 ;
const int N = 5005;
const int mod = 1e9 + 7;

int dx[4] = {-1 , 0 , 1 , 0};
int dy[4] = {0 , 1 , 0 , -1};

int a[N][N] , d[N][N];
bool vis[N][N];

struct Node{
	int dis , u , v;
	Node () {};
	Node ( int _dis , int _u , int _v ) : dis(_dis) , u(_u) , v(_v) {};
};

class Compare{
	public:
		bool operator () ( const Node &a , const Node &b ) {
			return a.dis > b.dis;
		}
};

signed main (){
	ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for ( int i = 1 ; i <= n ; i++ ){
    	for ( int j = 1 ; j <= n ; j++ ) {
    		char c;
    		cin >> c;
    		a[i][j]=c-'0';
		}
	}

		for ( int i = 1 ; i <= n ; i++ ){
			for ( int j = 1 ; j <= n ; j++ ) d[i][j] = 1e18;
		}
		memset(vis , false , sizeof(vis));
		priority_queue<Node , vector<Node> , Compare>pq;
		int x=1, y=1, z=n, t=n;
		d[x][y] = 0;
		pq.push({d[x][y] , x , y});
		while(!pq.empty()){
			int u = pq.top().u , v = pq.top().v;
			pq.pop();
			if ( vis[u][v] ) continue;
			vis[u][v] = true;
			for ( int i = 0 ; i < 4 ; i++ ){
				int i1 = u + dx[i];
				int j1 = v + dy[i];
				if ( i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= n ){
						if ( d[i1][j1] > d[u][v] + 1){
                            cout<<i1<<" "<<j1<<endl;
							d[i1][j1] = d[u][v] + 1;
							pq.push(Node(d[i1][j1] , i1 , j1));
						}

		}
        }
		}

		cout << d[z][t] << el;
	}
