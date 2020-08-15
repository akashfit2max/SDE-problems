class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
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
            if (i > pos && candidates[i - 1] == candidates[i]) // skip duplicates
                continue;
            if (target - candidates[i] < 0)
                return;
            v.push_back(candidates[i]);
            Sum(ans, v, candidates, target - candidates[i], i + 1);
            v.pop_back();
        }
    }
};