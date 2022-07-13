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
    vector<vector<int>> res;
    void solve(TreeNode* root, int lvl){
        vector<int> ans;
        if(root==NULL)
            return ;
        
        
        if(lvl==res.size())
            res.push_back(ans);  
        
        
        solve(root->left,lvl+1);
        
        solve(root->right,lvl+1);
        res[lvl].push_back(root->val);
       

        
        
        
        
        
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        solve(root, 0);
        return res;
    }
};
