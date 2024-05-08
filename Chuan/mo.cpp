#include<bits/stdc++.h>
using namespace std;
#define int long long

const int maxn=1e5+7;
int cnt1[maxn], cnt2[maxn];
int n, q;
int arr[maxn];
int ans[maxn];
int S=500;

struct Query
{
    int l, r, x, idx;
} qr[maxn];


bool cmp(Query A, Query B)
{
    if (A.l/S!=B.l/S)
    {
        return A.l/S<B.l/S;
    }
    return A.r<B.r;
}

void add(int x)
{
    cnt2[cnt1[x]]--;
    cnt1[x]++;
    cnt2[cnt1[x]]++;
}

void del(int x)
{
    cnt2[cnt1[x]]--;
    cnt1[x]--;
    cnt2[cnt1[x]]++;
}

signed main()
{
   ios_base::sync_with_stdio(false);cin.tie(NULL);
   cin >> n >> q;
   for (int i=1; i<=n; i++)
   {
       cin >> arr[i];
   }
   for (int i=1; i<=q; i++)
   {
       cin >> qr[i].l >> qr[i].r >> qr[i].x;
       qr[i].idx=i;
   }
   sort(qr + 1, qr + q + 1, cmp);
   int l=1, r=0;
   for (int i=1; i<=q; i++)
   {
        //cout << qr[i].l << ' ' << qr[i].r << '\n';
        while(r < qr[i].r) add(arr[++r]);
        while(r > qr[i].r) del(arr[r--]);
        while(l < qr[i].l) del(arr[l++]);
        while(l > qr[i].l) add(arr[--l]);
       // cout<<cnt2[qr[i].x]<<endl;
        ans[qr[i].idx] = cnt2[qr[i].x];
   }
   for (int i=1; i<=q; i++) cout<<ans[i]<<endl;
}