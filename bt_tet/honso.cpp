#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 7;
int a1,b1,c1,a2,b2,c2,a3,b3,c3;
void rut_gon(int a, int b, int c)
{
    if (abs(b)>abs(c))
    {
        int cong=b/c;
        a+=cong;
        b-=c*cong;
    }
    int g=abs(__gcd(b,c));
    b/=g;
    c/=g;
    if ((b<0&&a<0)||(c<0&&a<0))
    cout<<a<<" "<<abs(b)<<" "<<abs(c);
    else if (b<0&&c<0&&a<0) cout<<a<<" "<<abs(b)<<" "<<abs(c);
    else cout<<a<<" "<<b<<" "<<c;
}
void rut_gon_dg(int a, int b, int c)
{
    int g=abs(__gcd(b,c));
    b/=g;
    c/=g;
    if ((b<0&&a<0)||(c<0&&a<0))
    cout<<a<<" "<<abs(b)<<" "<<abs(c);
    else if (b<0&&c<0&&a<0) cout<<a<<" "<<abs(b)<<" "<<abs(c);
    else cout<<a<<" "<<b<<" "<<c;
}
void cong()
{
    int adu=a1+a2+a3;
    int chu_dong_tu=b1*c2*c3+b2*c1*c3+b3*c1*c2;
    int mau=c1*c2*c3;
    rut_gon(adu,chu_dong_tu,mau);
}
void tru()
{
    int adu=a1-a2-a3;
    int chu_dong_tu=b1*c2*c3-b2*c1*c3-b3*c1*c2;
    int mau=c1*c2*c3;
    rut_gon(adu,chu_dong_tu,mau);
}
void nhan()
{
    int adu=0;
    int chu_dong_tu=(c1*a1+b1)*(c2*a2+b2)*(c3*a3+b3);
    int mau=c1*c2*c3;
    rut_gon(adu, chu_dong_tu,mau);
}
void chia()
{
    int adu=0;
    int chu_dong_tu=c3*c2*(a1*c1+b1);
    int mau=c1*(a2*c2+b2)*(a3*c3+b3);
    rut_gon(adu,chu_dong_tu,mau);
}
void lon()
{
    if ((a1*c1+b1)*c2>c1*(a2*c2+b2)&&(a1*c1+b1)*c3>c1*(a3*c3+b3)) rut_gon_dg(a1,b1,c1);
    else if ((a1*c1+b1)*c2<c1*(a2*c2+b2)&&(a2*c2+b2)*c3>c2*(a3*c3+b3)) rut_gon_dg(a2, b2, c2);
    else if ((a3*c3+b3)*c1>c3*(a1*c1+b1)&&(a3*c3+b3)*c2>c3*(a2*c2+b2)) rut_gon_dg(a3,b3,c3);
}
bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
    return (a.first*a.second.second+a.second.first)*b.second.second>(b.first*b.second.second+b.second.first)*a.second.second;
}
void giam()
{
 vector<pair<int, pair<int, int> > > v;
 v.push_back({a1,{b1,c1}});
 v.push_back({a2,{b2,c2}});
 v.push_back({a3,{b3,c3}});  
 sort(v.begin(), v.end(), cmp);
 for (auto x:v)
 {
    rut_gon_dg(x.first, x.second.first, x.second.second);
    cout<<" ";
    //cout<<x.first<<" "<<x.second.first<<" "<<x.second.second<<" ";
 } 

}
signed main() {
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2 >> a3 >> b3 >> c3;
    cong();
    cout<<endl;
    tru();
    cout<<endl;
    nhan();
    cout<<endl;
    chia();
    cout<<endl;
    lon();
    cout<<endl;
    giam();
}
