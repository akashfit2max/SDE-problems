class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        heights.push_back(0);
        int size = heights.size();
        stack<int> s;
        int i = 0, maxrect = 0;
        while (i < size)
        {
            if (s.empty() || heights[i] > heights[s.top()])
            {
                s.push(i++);
            }
            else
            {
                int h = s.top();
                s.pop();
                maxrect = max(maxrect, heights[h] * (s.empty() ? i : i - s.top() - 1));
            }
        }
        return maxrect;
    }
};