class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> v;
        Sum(ans, v, candidates, target, 0);

        return ans;
    }

    void Sum(vector<vector<int>> &ans, vector<int> v, vector<int> &candidates, int target, int pos)
    {

        if (target == 0)
            ans.push_back(v);

        for (int i = pos; i < candidates.size(); i++)
        {
            if (target - candidates[i] < 0)
                return;
            v.push_back(candidates[i]);
            Sum(ans, v, candidates, target - candidates[i], i);
            v.pop_back();
        }
    }
};