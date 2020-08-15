class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int m = haystack.size(), n = needle.size(), i, j;
        for (i = 0; i <= m - n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (haystack[i + j] != needle[j])
                {
                    break;
                }
            }
            if (j == n)
            {
                return i;
            }
        }
        return -1;
    }
};

// haystack.find(needle) alternatte sol one liner
