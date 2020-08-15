void printLeftview(bool *levels, Node *root, int curr)
{
    if (!root)
        return;

    if (levels[curr] == false)
    {
        levels[curr] = true;
        cout << root->data << " ";
    }
    printLeftview(levels, root->left, curr + 1);  //left child called
    printLeftview(levels, root->right, curr + 1); //right child called
}

void leftView(Node *root)
{
    // Max height of tree assumed to be 100
    //Therefore for skew tree, max levels = 100
    bool levels[202] ={ false };
    printLeftview(levels, root, 0);
}









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
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<int> view;
        queue<TreeNode*> todo;
        todo.push(root);
        while (!todo.empty()) {
            int n = todo.size();
            for (int i = 0; i < n; i++) {
                TreeNode* node = todo.front();
                todo.pop();
                if (i == 0) {
                    view.push_back(node->val);
                }
                if (node->left) {
                    todo.push(node->left);
                }
                if (node->right) {
                    todo.push(node->right);
                }
            }
        }
        return view;
    }
};