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
    vector<int> gTemp;
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL)
            return vector<int>{};
        
        
        inorderTraversal(root->left);
        gTemp.push_back(root->val);
        inorderTraversal(root->right);

        return gTemp;
    }
};