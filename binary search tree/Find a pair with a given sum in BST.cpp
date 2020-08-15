/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<int> v;
    void trav(TreeNode *root)
    {
        if (root == NULL)
            return;
        trav(root->left);
        v.push_back(root->val);
        trav(root->right);
    }
    bool findTarget(TreeNode *root, int k)
    {
        trav(root);
        int i = 0, j = v.size() - 1;
        while (i < j)
        {
            if (v[i] + v[j] == k)
                return true; //two pointer approach to find if answer exists.
            else if (v[i] + v[j] < k)
                i++;
            else
                j--;
        }
        return false;
    }
};