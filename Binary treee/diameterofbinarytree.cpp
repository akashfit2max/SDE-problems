/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int height(TreeNode *root)
{
    if (root == nullptr)
        return 0;
    return max(height(root->left), height(root->right)) + 1;
}
class Solution
{
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int left_height = height(root->left);
        int right_height = height(root->right);

        int left_dia = diameterOfBinaryTree(root->left);
        int right_dia = diameterOfBinaryTree(root->right);

        return max(left_height + right_height, max(left_dia, right_dia));
    }
};