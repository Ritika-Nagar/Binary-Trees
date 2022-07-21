class Solution
{
    public:
    // void solve(Node* root, int n, vector<int> &ans){
        
    //     if(root==NULL || root->data==n){
            
    //         return;
    //     }
        
    //     ans.push_back(root->data);
        
    //     solve(root->left,n, ans);
    //     solve(root->right,n, ans);
    // }
    
    // //Function to return the lowest common ancestor in a Binary Tree.
    // Node* lca(Node* root ,int n1 ,int n2 )
    // {   
    //   vector<int> ans1;
       
    //   solve(root,n1, ans1);
    //   vector<int> ans2;
    //   solve(root, n2, ans2);
       
    //   int d;
    //   for(int i=ans1.size();i>=0;i--){
    //       for(int j=ans2.size();j>=0;j--){
    //           if(ans1[i]==ans2[j]){
    //               d= ans1[i];
    //               break;
    //           }
    //       }
    //   }
      
    //   Node* newR= new Node(d);
    //   return newR;
       
       
    // }
    
    Node* lca(Node* root ,int n1 ,int n2 ){
        // base case 
        if(root==NULL){
            return NULL;
        }
        
        if(root->data==n1 || root->data==n2){
            return root;
        }
        
        Node* leftAns= lca(root->left, n1, n2);
        Node* rightAns= lca(root->right, n1,n2);
        
        if(leftAns!=NULL && rightAns!=NULL){
            return root;
        }else if(leftAns!=NULL && rightAns==NULL){
            return leftAns;
        }else if(leftAns==NULL && rightAns!=NULL){
            return rightAns;
        }else{
            return NULL;
        }
    }
    
};
