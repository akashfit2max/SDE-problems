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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return helper(0, 0, inorder.size() - 1, preorder, inorder);
    }

    TreeNode *helper(int prestart, int instart, int inend, vector<int> &preorder, vector<int> &inorder)
    {
        if (prestart > preorder.size() - 1 || instart > inend)
        {
            return nullptr;
        }

        TreeNode *root = new TreeNode(preorder[prestart]);
        //find the index of root in inorder
        int in_index = 0;
        for (int i = instart; i <= inend; i++)
        {
            if (root->val == inorder[i])
            {
                in_index = i;
            }
        }
        root->left = helper(prestart + 1, instart, in_index - 1, preorder, inorder);
        root->right = helper(prestart + in_index - instart + 1, in_index + 1, inend, preorder, inorder);

        return root;
    }
};

class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int rootIdx = 0;
        return build(preorder, inorder, rootIdx, 0, inorder.size() - 1);
    }

    TreeNode *build(vector<int> &preorder, vector<int> &inorder, int &rootIdx, int left, int right)
    {
        if (left > right)
            return NULL;
        int pivot = left; // find the root from inorder
        while (inorder[pivot] != preorder[rootIdx])
            pivot++;

        rootIdx++;
        TreeNode *newNode = new TreeNode(inorder[pivot]);
        newNode->left = build(preorder, inorder, rootIdx, left, pivot - 1);
        newNode->right = build(preorder, inorder, rootIdx, pivot + 1, right);
        return newNode;
    }
};