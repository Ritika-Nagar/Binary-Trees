class Solution{
    private: 
    int height(struct Node* node){
        if(node==NULL)
            return 0;
    
        return max(height(node->left), height(node->right))+1;// left subtree ki height nikaal lo..fir right subtree ki nikaal lo plus root ko or add kr do 
    }
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {   if(root==NULL){
            return true;
        }
        
        bool left= isBalanced(root->left);
        bool right= isBalanced(root->right);
        
        bool diff= abs(height(root->left)- height(root->right))<=1;
        
        if(left && right && diff){
            return true;
        }
        
        return false;
        
    }
    
    // Time complexity: O(N^2)
};
