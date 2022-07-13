pair<int,int> diameterFast(struct Node* root){
        if(root==NULL){
            pair<int,int>p= make_pair(0,0);
            return p;
        }
        
        pair<int,int> left=diameterFast(root->left);
        pair<int,int> rght=diameterFast(root->right);
        
        int opt1= left.first;  // diamter from left subtree
        int opt2= rght.first;
        int opt3= left.second+1+rght.second;
        
        pair<int,int> ans;
        ans.first= max(opt1,max(opt2,opt3));
        ans.second= max(left.second, rght.second)+1;
        return ans;
        
        
    }
    
    
    int diameter(struct Node* root) {
       
        // if(root==NULL)
        //   return 0;
        
        
        // // hum har ek node par khade ho kar teen cheeze kar rhe h
        // int l=diameter(root->left);
        // int r= diameter(root->right);
        // // wrong way 
        // // int l_r= diameter(root->left)+1+diameter(root->right);
        // int l_r=height(root->left)+1+height(root->right);
        
        // return max(l, max(r,l_r));
        
        return diameterFast(root).first;
       
       
       
    }
