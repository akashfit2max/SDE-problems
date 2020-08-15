// Minimum Number of Arrows to Burst Balloons
// this is  an activity selection problem

class Solution
{
public:
    int findMinArrowShots(vector<pair<int, int>> &points)
    {
        int count = 0, arrow = INT_MIN;
        sort(points.begin(), points.end(), mysort);
        for (int i = 0; i < points.size(); i++)
        {
            if (arrow != INT_MIN && points[i].first <= arrow)
            {
                continue;
            }                         //former arrow shot points[i]
            arrow = points[i].second; // new arrow shot the end of points[i]
            count++;
        }
        return count;
    }
    static bool mysort(pair<int, int> &a, pair<int, int> &b)
    {
        return a.second == b.second ? a.first < b.first : a.second < b.second;
        // return a.second < b.second this will also work fine
    }
};



class Solution
{
public:
    int findMinArrowShots(vector<vector<int>> &p)
    {
        sort(p.begin(), p.end(), [](vector<int> &a, vector<int> &b) {
            // if(a[1]==b[1])return a[0]<b[0];
            return a[1] < b[1];
        });
        int ans = 0, n = p.size();
        if (n == 0)
            return 0;
        ans = 1;
        int prev = p[0][1];
        for (int i = 1; i < n; i++)
        {
            if (prev >= p[i][0])
                continue;
            ans++;
            prev = p[i][1];
        }
        return ans;
    }
};
