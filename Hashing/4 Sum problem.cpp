class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> res;
        int n = nums.size();
        if (n == 0)
        {
            return res;
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n - 2; j++)
            {
                //two pointer approach
                if (j > 1 && nums[j] == nums[j - 1] && (j - i) > 1)
                    continue;
                int k = j + 1;
                int l = n - 1;
                while (k < l)
                {
                    if (nums[i] + nums[j] + nums[k] + nums[l] - target == 0)
                    {
                        res.push_back({nums[i], nums[j], nums[k], nums[l]});
                        while (k + 1 < l - 1 && nums[k] == nums[k + 1] && nums[l] == nums[l - 1])
                        {
                            k++;
                            l--;
                        }
                        k++;
                        l--;
                    }
                    else if (nums[i] + nums[j] + nums[k] + nums[l] - target > 0)
                    {
                        l--;
                    }
                    else
                    {
                        k++;
                    }
                }
            }
        }
        return res;
    }
};