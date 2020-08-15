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
    vector<int> vec;
    void inorder(TreeNode *x)
    {
        if (x == nullptr)
        {
            return;
        }
        inorder(x->left);
        vec.push_back(x->val);
        inorder(x->right);
    }
    bool isValidBST(TreeNode *root)
    {
        vec.clear();
        inorder(root);

        for (int i = 1; i < vec.size(); i++)
        {
            if (vec[i] <= vec[i - 1])
                return false;
        }
        return true;
    }
};