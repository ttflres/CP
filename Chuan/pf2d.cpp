vector< vector<int> > build2DPrefixSum(const vector< vector<int> >& a) {
    int m = (int)a.size(), n = (int)a[0].size();

    vector< vector<int> > prefixSum(m + 1, vector<int> (n + 1, 0));

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1] + a[i - 1][j - 1]; // ta truy cập a(i - 1, j - 1) do mảng A là 0-indexed
    return prefixSum;
}
x1 y1 x2 y2
-> Sx2y2-Sx1-1y2-Sx2y1-1+Sx1-1y1-1
