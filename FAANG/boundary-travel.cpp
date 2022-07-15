class Solution {
public:
    void traverseLeft(Node*root, vector<int>& ans){
        // base case
        if((root==NULL) || (root->left==NULL && root->right==NULL)){// leaf node chodna h
            return ;
        }
        
        ans.push_back(root->data);
        if(root->left){
            traverseLeft(root->left, ans);
        }else{
            traverseLeft(root->right, ans);
        }
        
        
        
    }
    
    void traverseLeaf(Node* root, vector<int>& ans){
        // base case 
        if(root==NULL){
            return;
        }
        
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->data);
            return;
        }
        
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right,ans);
    }
    
    void traverseRight(Node* root, vector<int>& ans){
        if((root==NULL) || (root->left==NULL && root->right==NULL)){// leaf node chodna h
            return ;
        }
        
        if(root->right){
            traverseRight(root->right, ans);
        }else{
            traverseRight(root->left, ans);
        }
        ans.push_back(root->data);
        
    }
    vector <int> boundary(Node *root)
    {   
        vector<int> ans;
        if (root==NULL)
            return ans;
        
        
        ans.push_back(root->data);
        // traverse left first 
        traverseLeft(root->left, ans);
        
        // traverse over leaf nodes 
        traverseLeaf(root->left, ans);// left subtree
        traverseLeaf(root->right, ans);// right subtree
        
        
        // traverse over right part 
        traverseRight(root->right, ans);// tu bhej hi root ke right part ko rhih ..basically apna right subtree bhej rhi h..root kaa koi roll nhi h yhn a
        
        return ans;
    }
};
