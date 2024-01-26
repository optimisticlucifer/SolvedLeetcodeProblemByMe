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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        if(root == nullptr)
            return result;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int levelSize = q.size();
            vector<int> levelValues;
            
            for(int i = 0; i < levelSize; i++){
                TreeNode* currentNode = q.front();
                q.pop();
                
                levelValues.push_back(currentNode->val);
                
                if(currentNode->left != nullptr) 
                    q.push(currentNode->left);
                if(currentNode->right != nullptr) 
                    q.push(currentNode->right);
            }
            
            result.push_back(levelValues);
        }
        
        return result;
    }
};