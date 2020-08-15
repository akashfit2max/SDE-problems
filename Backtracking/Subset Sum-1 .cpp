// Partition Equal Subset Sum

class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (auto i : nums)
        {
            sum += i;
        }
        if (sum % 2)
            return false;
        sum = sum / 2;
        sort(nums.begin(), nums.end());
        return helper(nums, sum, nums.size() - 1);
    }

    bool helper(vector<int> &nums, int sum, int index)
    {
        if (index >= nums.size())
        {
            return false;
        }
        if (sum == nums[index])
            return true;
        if (sum < nums[index])
            return false;
        return helper(nums, sum - nums[index], index - 1) || helper(nums, sum, index - 1);
    }
};