int printnse(vector<int> &nums)
{
    stack<int> s;
    vector<int> v;
    s.push(nums[0]);
    for (int i = 1; i < nums.size(); i++)
    {
        while (!s.empty() && nums[s.top()] > nums[i])
        {
            v.push_back(nums[i]);
        }
        s.push(nums[i]);
    }
    while (!s.empty())
    {
        v.push_back(-1);
    }
    return v;
}