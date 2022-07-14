 */
class Solution {
public:
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int & rootIndx, int l,int r ){
        if(l>r)return NULL;
        int pivot= l;// find the root from inorder 
        // basically hum pivot ko bol rahe h ki tu ab ynha se elem ko dhundna shuru kar
        // ishe puri array me nhi dhund rahe h ...humne apna search area reduce kar diya h
        while(inorder[pivot]!=preorder[rootIndx])pivot++;
        rootIndx++;
        
        TreeNode* newNode= new TreeNode(inorder[pivot]);
        //Lets go towards the left and right subtree
        newNode->left= build(preorder, inorder, rootIndx, l, pivot-1);
        newNode->right= build(preorder, inorder, rootIndx, pivot+1, r);
        return newNode;
        
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int rootIndx=0;
        return build(preorder, inorder, rootIndx, 0, inorder.size()-1);
    }
};
