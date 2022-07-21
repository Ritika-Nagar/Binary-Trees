class Solution
{
public:
    
    void solve(Node* root, int &maxSum, int sum ,int & maxLen, int len ){
        // base case 
        if(root==NULL){
            if(len>maxLen){
                maxLen=len;
                maxSum=sum;
            }else if(len==maxLen){
                maxSum= max(sum, maxSum);
            }
            
            return ;
            
        }
        
        
        sum=sum+root->data;
        
        solve(root->left, maxSum, sum, maxLen, len+1);
        solve(root->right, maxSum, sum , maxLen, len+1);
        
    } 
        
        
    int sumOfLongRootToLeafPath(Node *root)
    {   int sum=0; 
        int len=0;
        int maxLen=0;
        int maxSum=INT_MIN;
        
        solve(root, maxSum, sum, maxLen,len);
        
        return maxSum;
    }
};
