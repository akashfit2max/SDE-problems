int Solution::findMedian(vector<vector<int>> &A)
{
    int n = A.size();
    int m = A[0].size();

    int mi = A[0][0];
    int mx = A[0][m - 1];

    for (int i = 0; i < n; i++)
    {
        mi = min(A[i][0], mi);
        mx = max(A[i][m - 1], mx);
    }
    int desired = (m * n + 1) / 2;
    while (mi < mx)
    {
        int mid = mi + (mx - mi) / 2;
        int place = 0;

        // Find count of elements smaller than mid
        for (int i = 0; i < n; ++i)
            place += upper_bound(A[i].begin(), A[i].end(), mid) - A[i].begin();
        if (place < desired)
            mi = mid + 1;
        else
            mx = mid;
    }
    return mi;
}
