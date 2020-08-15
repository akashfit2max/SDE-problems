/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return nullptr;
        }
        return arraytobst(nums, 0, nums.size() - 1);
    }

    TreeNode *arraytobst(vector<int> &nums, int left, int right)
    {
        if (left > right)
        {
            return nullptr;
        }
        int midpoint = left + (right - left) / 2;
        TreeNode *root = new TreeNode(nums[midpoint]);
        root->left = arraytobst(nums, left, midpoint - 1);
        root->right = arraytobst(nums, midpoint + 1, right);

        return root;
    }
};