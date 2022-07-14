
void solve(Node* root, int len, int sum, int& maxSum, int& maxLen){
        // base case 
        if(root==NULL){
            if(len>maxLen){
                maxLen=len;
                maxSum=sum;
            }else if(maxLen==len){
                maxSum=max(sum, maxSum);
            }
            return;
        }
        
        sum=sum+root->data;
        solve(root->left, len+1,sum,maxSum, maxLen);
        solve(root->right, len+1,sum,maxSum, maxLen);
        
        
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {   int maxSum=INT_MIN;
        int len=0;
        int sum=0;
        int maxLen=0;
        solve(root,len,sum,maxSum,maxLen);
        return maxSum;
    }
};
