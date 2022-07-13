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
    
//     void solve(TreeNode* root){
//         queue<TreeNode*>st;
//         st.push(root);
//         st.push(NULL);
        
//         while(!st.empty()){
//             TreeNode* temp= st.front();
//             st.pop();
//             vector<int>a;
//             if(temp==NULL){
//                 cout<<endl;
//                 res.push_back(a);
//                 if(!st.empty()){
//                     st.push(NULL);
//                 }
//             }else{
//                 vector<int>ans;
//                 ans.push_back(temp->val);
//                 ans=a;
//                 cout<<temp->val<<" ";
                
//                 if(temp->left){
//                     st.push(temp->left);
//                 }
//                 if(temp->right){
//                     st.push(temp->right);
//                 }
//             }
            
            
            
//         }
//     }
    
    int depth(TreeNode* root){
        // base case
        if(root==NULL)return 0;
        // it return the maximum depth of the tree , so to find the levels 
        return max(depth(root->left),depth(root->right))+1;
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root==NULL)return {};
        int d= depth(root);
        
        // Initialising the empty levels inside a vector 
        vector<vector<int>>res(d, vector<int>({}));
        int i=0;
        
        //using queue to maintain the tree nodes
        queue<TreeNode*>q;
        q.push(root);
        res[d-1].push_back(root->val);
        q.push(NULL);
        d--;
        
        while(!q.empty()){
            TreeNode* temp= q.front();
            q.pop();
            
            if(temp==NULL){
                if(q.empty())break;// matlab sab khaali ho gya h ..bahar nikal jao
                d--;
                q.push(NULL);
            }else{
                
                if(temp->left){
                    q.push(temp->left);
                    res[d-1].push_back(temp->left->val);
                }
                
                if(temp->right){
                    q.push(temp->right);
                    res[d-1].push_back(temp->right->val);
                }
            }
        }
        
        return res;
    }
};
