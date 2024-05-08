#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
typedef struct Vector {
	int x,y,id;
	Vector operator - (const Vector &o) {
		return {x-o.x,y-o.y};
	}
	int cross (const Vector &o) {
		return x*o.y - y*o.x;
	}
	bool operator < (const Vector &o) const {
		return x < o.x || (x == o.x && y < o.y);
	}
}point;
int direc (point a, point b, point c) {
	Vector x = b - a;
	Vector y = c - b;
	return x.cross(y);
}
bool ccw (point a, point b, point c) {
	return direc(a,b,c) > 0;
}

bool cw (point a, point b, point c) {
	return direc (a,b,c) < 0;
}

vector<point> convex_hull (vector<point> a) {
	sort (a.begin(),a.end());
	point first = a[0];
	point last = a.back();
	vector<point> up,down;
	up.push_back(first);
	down.push_back(first);
	int dak = a.size();
	for (int i=1; i<dak; i++) {
		if (i == dak-1 || cw (first,a[i],last)) {
			while (up.size() >= 2 && !cw(up[up.size()-2],up.back(),a[i])) up.pop_back();
			up.push_back(a[i]);
		}
		if (i == dak-1 || ccw (first,a[i],last)) {
			while (down.size()>=2 && !ccw(down[down.size()-2],down.back(),a[i])) down.pop_back();
			down.push_back(a[i]);
		}
	}
	a.clear();
	for (int i=0; i<up.size(); i++) a.push_back(up[i]);
	int g = down.size();
	for (int i = g - 2; i>=1; i--) a.push_back(down[i]);
	return a;
}
int cnt;
long double bp (long double x) {
	return x*x;
}
long double dist (point a, point b) {
	return sqrtl(bp(a.x-b.x)+bp(a.y-b.y));
}
const int N = 2e5+5;
int b[N];
long double P (vector<point> &a) {
	int n = a.size();
	a.push_back(a[0]);
	long double res = 0;
	for (int i=0; i<n; i++) res = res + dist (a[i],a[i+1]);
	a.pop_back();
	return res;
}
long double s(point a, point b, point c)
{
    point ab, ca;
    ab.x=b.x-a.x;
    ab.y=b.y-a.y;
    ca.x=c.x-a.x;
    ca.y=c.y-a.y;
    return fabs(ab.x*ca.y-ca.x*ab.y)/2;
}
void solve () {
	int n; cin >> n;
	vector<point> a;
	for (int i=1; i<=n; i++) {
		int x,y; cin >> x >> y;
		a.push_back({x,y});
	}
	a = convex_hull(a);
	long double ans=0;
	for (int i=0; i<a.size()-2; i++)
    {
        for (int j=i+1; j<a.size(); j++)
        {
            for (int t=i+2; t<a.size(); t++)
            {
                ans=max(ans, s(a[i], a[t], a[j]));
            }
        }
    }
    cout<<setprecision(1)<<fixed<<ans;

}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	solve();
}
