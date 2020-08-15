/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//  Binary Tree Level Order Traversal
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>result;
        if(root==nullptr){
            return result;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()) {
            int size=q.size();
            vector<int>v;
            for(int i=0;i<size;i++){
                TreeNode* temp=q.front();
                q.pop();
                v.push_back(temp->val);
                if(temp->left!=nullptr)
                q.push(temp->left);
                if(temp->right!=nullptr)
                q.push(temp->right);
            }
            result.push_back(v);
        }
        return result;
    }
     
};