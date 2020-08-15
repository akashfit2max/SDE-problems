class Solution
{
public:
    int trap(vector<int> &height)
    {
        int left = 0, right = height.size() - 1;
        if (right < 2)
            return 0;
        int leftMax = height[left], rightMax = height[right], second;
        int area = 0;
        while (left < right)
        {
            leftMax = max(leftMax, height[left]);
            rightMax = max(rightMax, height[right]);
            second = min(leftMax, rightMax);
            if (height[left] < height[right])
            {
                area += second - height[left];
                left++;
            }
            else
            {
                area += second - height[right];
                right--;
            }
        }
        return area;
    }
};



//java
class Solution
{
public
    int trap(int[] A)
    {
        int a = 0;
        int b = A.length - 1;
        int max = 0;
        int leftmax = 0;
        int rightmax = 0;
        while (a <= b)
        {
            leftmax = Math.max(leftmax, A[a]);
            rightmax = Math.max(rightmax, A[b]);
            if (leftmax < rightmax)
            {
                max += (leftmax - A[a]); // leftmax is smaller than rightmax, so the (leftmax-A[a]) water can be stored
                a++;
            }
            else
            {
                max += (rightmax - A[b]);
                b--;
            }
        }
        return max;
    }
};