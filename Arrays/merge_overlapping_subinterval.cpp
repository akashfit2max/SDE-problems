static bool comp(vector<int> &a, vector<int> &b)
{
    return a[0] < b[0];
}
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> result;
        if (intervals.empty())
            return result;
        sort(intervals.begin(), intervals.end(), comp);
        vector<int> temporary = intervals[0];

        for (auto interval : intervals)
        {
            if (temporary[1] < interval[0])
            {
                result.push_back(temporary);
                temporary = interval;
            }
            else
            {
                temporary[1] = max(temporary[1], interval[1]);
            }
        }
        result.push_back(temporary);
        return result;
    }
};