class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int n = s.length();
        vector<bool> dp(n + 1, false);
        dp[0] = true;
        for (int lo = 0; lo < n; lo++)
        {
            if (dp[lo] == false)
            {
                continue;
            }
            for (auto word : wordDict)
            {
                int hi = word.length();
                if (hi <= n && s.substr(lo, hi) == word)
                {
                    dp[hi + lo] = true;
                }
            }
        }
        return dp[n];
    }
};