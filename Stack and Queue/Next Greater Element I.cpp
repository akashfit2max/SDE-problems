class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> mp;
        stack<int> s;
        for (auto num : nums2)
        {
            while (!s.empty() && s.top() < num)
            {
                mp.insert({s.top(), num});
                s.pop();
            }
            s.push(num);
        }
        for (int i = 0; i < nums1.size(); i++)
        {
            if (mp.find(nums1[i]) != mp.end())
            {
                nums1[i] = mp[nums1[i]];
            }
            else
            {
                nums1[i] = -1;
            }
        }
        return nums1;
    }
};

// https://leetcode.com/problems/next-greater-element-i/

//next greateer element II
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        stack<int> s;
        vector<int> ans(n, -1);
        for (int i = 0; i < n * 2; i++)
        {
            while (!s.empty() && nums[s.top()] < nums[i % n])
            {
                ans[s.top()] = nums[i % n];
                s.pop();
            }
            if (i < n)
            {
                s.push(i);
            }
        }
        return ans;
    }
};