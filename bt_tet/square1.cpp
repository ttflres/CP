#include <bits/stdc++.h>

int m, n;
int h[1000], l[1000], r[1000];

int main() {
    int i, j, xx, t, result = 0;
    scanf("%d%d", &m, &n);
    for(i=0;i<m;++i) {
        for(j=0;j<n;++j) {
            scanf("%d", &xx);
            h[j] = (xx==1) ? h[j]+1 : 0;
        }
        for(j=0;j<n;++j) {
            t = j-1;
            while(t>=0 && h[t]>=h[j]) t = l[t];
            l[j] = t;
        }
        for(j=n-1;j>=0;--j) {
            t = j+1;
            while(t<n && h[t]>=h[j]) t = r[t];
            r[j] = t;
            result =std::max(result, h[j] * (r[j]-l[j]-1));
        }
    }
    std::cout<<sqrt(result);
    return 0;
}
