class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> res;
        deque<int> deq;
        for (int i = 0; i < nums.size(); i++)
        {
            while (!deq.empty() && nums[i] >= nums[deq.back()])
            {
                deq.pop_back();
            }
            deq.push_back(i);
            if (deq.front() == i - k)
            {
                deq.pop_front();
            }
            if (i >= k - 1)
            {
                res.push_back(nums[deq.front()]);
            }
        }
        return res;
    }
};