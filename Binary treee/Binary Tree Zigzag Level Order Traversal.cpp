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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        vector<vector<int>> res;
        queue<TreeNode *> q;
        q.push(root);
        int lvl = 0; //maintain the lvl of thee tree
        while (!q.empty())
        {
            int size = q.size();
            vector<int> curr;
            while (size--)
            {
                TreeNode *temp = q.front();
                q.pop();
                curr.push_back(temp->val);
                if (temp->left != nullptr)
                {
                    q.push(temp->left);
                }
                if (temp->right != nullptr)
                {
                    q.push(temp->right);
                }
            }
            if (lvl % 2 != 0)
            {
                reverse(curr.begin(), curr.end());
            }
            lvl++;
            res.push_back(curr);
        }
        return res;
    }
};