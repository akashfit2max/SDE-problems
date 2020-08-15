class Solution
{
public:
    int longestConsecutive(vector<int> &num)
    {
        if (num.empty())
        {
            return 0;
        }
        if (num.size() == 1)
        {
            return 1;
        }
        unordered_set<int> record(num.begin(), num.end());
        int res = 1;
        for (int n : num)
        {
            record.erase(n);
            int prev = n - 1, next = n + 1;
            while (record.find(prev) != record.end())
                record.erase(prev--);
            while (record.find(next) != record.end())
                record.erase(next++);
            res = max(res, next - prev - 1);
        }
        return res;
    }
};