class Solution
{
public:
    int minCut(string s)
    {
        int N = s.size();
        vector<bool> ispalin(N + 1, false);
        vector<int> dp(N + 1, INT_MAX);
        dp[0] = -1;
        for (int i = 1; i < N + 1; i++)
        {
            ispalin[i] = true;
            for (int j = 1; j < i; j++)
            {
                ispalin[j] = ispalin[j + 1] && (s[j - 1] == s[i - 1]);
            }
            for (int j = 0; j < i; j++)
            {
                if (ispalin[i - j])
                {
                    dp[i] = min(dp[i], dp[i - 1 - j] + 1);
                }
            }
        }
        return dp[N];
    }
};

https: //leetcode.com/problems/palindrome-partitioning-ii/