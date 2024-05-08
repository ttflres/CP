#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=2e5+7;

int q;
vector<int> v;

struct Query {
  char t;
  int x;
  
  Query(char _t = '_', int _x = 0) : t(_t), x(_x) {}
  
  void read() {
    cin >> this->t >> this->x;
  }
};

struct FenwickTree {
  int n;
  vector<int> bit;
  
  FenwickTree(int _n = maxn) : n(_n) {
    bit.assign(n, 0);
  }
  
  void update(int r, int x) {
    for (; r < n; r = (r | (r + 1))) {
      bit[r] += x;
    }
  }
  
  int sum(int r) {
    int s = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1) {
      s += bit[r];
    }
    return s;
  }
  
  int sum(int l, int r) {
    return sum(r) - sum(l - 1);
  }
};

FenwickTree bit;
vector<Query> Q;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> q;
    Q.resize(q);
    for (int i=0; i<q; i++)
    {
        Q[i].read();
        if (Q[i].t!='K') v.push_back(Q[i].x);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i=0; i<q; i++)
    {
        if (Q[i].t!='K')
        {
            Q[i].x=lower_bound(v.begin(), v.end(), Q[i].x)-v.begin();
        }
    }
    // cout<<bit.sum(0)<<endl;
    for (int i=0; i<q; i++)
    {
        if (Q[i].t=='I')
        {
            // cout<<"DCMM"<<endl;
            // cout<<sum(Q[i].x)<<endl;
            if (bit.sum(Q[i].x, Q[i].x)==0) bit.update(Q[i].x, 1);
        }
        else if (Q[i].t=='D')
        {
            // cout<<"DCMM"<<endl;
            // cout<<sum(Q[i].x)<<endl;
            if (bit.sum(Q[i].x, Q[i].x)==1) bit.update(Q[i].x, -1);
        }
        else if (Q[i].t=='K')
        {
                int res=-1;
                int l=0, r=maxn-1;
                while (l<=r)
                {
                    int mid=(l+r)/2;
                    if (bit.sum(mid)>=Q[i].x) 
                    {
                        res=mid;
                        r=mid-1;
                    }
                    else l=mid+1;
                }
                if (res==-1) cout<<"invalid"<<"\n";
                else cout<<v[res]<<"\n";
                // cout<<"DCMM"<<"\n";
        }
        else if (Q[i].t=='C')
        {
            cout<<bit.sum(Q[i].x-1)<<"\n";
        }
    }
}

