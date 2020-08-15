class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 0)
        {
            return "";
        }
        string prefix = strs[0];
        for (auto &s : strs)
        {
            if (s.length() == 0)
            {
                return "";
            }
            int i;
            for (i = 0; i < prefix.length() && i < s.length(); i++)
            {
                if (s[i] != prefix[i])
                {
                    break;
                }
            }
            prefix = prefix.substr(0, i);
        }
        return prefix;
    }
};