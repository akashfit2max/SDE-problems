class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int count = 0, max_len = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                count++;
            }
            else
            {
                count = 0;
            }
            max_len = max(max_len, count);
        }
        return max_len;
    }
};

/*Given an array A of 0s and 1s, we may change up to K values from 0 to 1.

Return the length of the longest (contiguous) subarray that contains only 1s. */

class Solution
{
public:
    int longestOnes(vector<int> &A, int K)
    {
        int i = 0, j = 0;
        while (i < A.size())
        {

            if (A[i] == 0)
            {
                K--;
            }
            if (K < 0)
            {
                if (A[j] == 0)
                {
                    K++;
                }
                j++;
            }
            i++;
        }
        return i - j;
    }
};