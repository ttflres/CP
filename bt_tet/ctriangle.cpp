#include <bits/stdc++.h>
using namespace std;
 
void CountTriangles(int A[], int n)
{
 
    sort(A, A+n);
 
    int count = 0;
 
    for (int i = n - 1; i >= 1; i--) {
        int l = 0, r = i - 1;
        while (l < r) {
            if (A[l] + A[r] > A[i]) {
                count += r - l;
                r--;
            }
            else
                l++;
        }
    }
    cout <<count<<endl;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i=0; i<n; i++) cin >> a[i];
    CountTriangles(a,n); 
    
    
}