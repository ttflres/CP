#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn = 1e5 + 7;
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i=0; i<n; i++) cin >> arr[i];
    int best = INT_MIN;
    int sum = 0;
    for (int i = 0; i < n; i ++) {
    sum = max(arr[i], sum + arr[i]);
    best = max(sum, best);
    }
    cout << best << "\n";
}
