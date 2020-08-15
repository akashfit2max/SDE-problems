class Solution
{
public:
    TreeNode *helper(int &prestrt, int instrt, int inend, vector<int> inorder, vector<int> postorder)
    {
        if (instrt > inend)
            return NULL;
        int temp = postorder[prestrt];
        TreeNode *root = new TreeNode(temp);
        prestrt--;
        if (instrt == inend)
            return root;

        int index = 0;
        for (int i = instrt; i <= inend; i++)
        {
            if (root->val == inorder[i])
            {
                index = i;
                break;
            }
        }
        root->right = helper(prestrt, index + 1, inend, inorder, postorder);
        root->left = helper(prestrt, instrt, index - 1, inorder, postorder);
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int s = postorder.size() - 1;
        return helper(s, 0, inorder.size() - 1, inorder, postorder);
    }
};