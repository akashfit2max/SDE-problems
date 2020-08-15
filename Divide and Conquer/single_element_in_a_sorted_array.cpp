class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        unordered_map<int, int> mp;
        for (auto num : nums)
        {
            mp[num]++;
        }
        for (auto i : mp)
        {
            if (i.second == 1)
            {
                return i.first;
            }
        }
        return -1;
    }
};

//binary search
int singleNonDuplicate(vector<int> &nums)
{
    int start = 0, end = nums.size() - 1, mid;
    while (start < end)
    {
        mid = start + (end - start) / 2;
        if (nums[mid] == nums[mid ^ 1])
            start = mid + 1;
        else
            end = mid;
    }
    return nums[start];
}



