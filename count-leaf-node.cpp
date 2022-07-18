/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>
    class BinaryTreeNode {
      public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
        }
    };
    
***********************************************************/

void solve(BinaryTreeNode<int> *root, int &ans){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        ans++;
        return;
       
    }
    
    solve(root->left, ans);
    solve(root->right,ans);
    
}
int noOfLeafNodes(BinaryTreeNode<int> *root){
    int ans=0;
    if(root==NULL)
        return 0;
    solve(root,ans);
    
    return ans;
}
