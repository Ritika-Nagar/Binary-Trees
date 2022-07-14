#include<iostream>
#include<queue>
using namespace std;
class node{
    public :
        int data;
        node* left;
        node* right;
    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};


// In order to build a tree
node* buildTree(node* root){
    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    root= new node(data);

    // base case
    if(data==-1){
        return NULL;
    }

    cout<<"Enter data for inserting in left "<<data<<endl;
    root->left= buildTree(root->left);
    cout<<"Enter data for inserting in right  "<<data<<endl;
    root->right= buildTree(root->right);

    return root;
}

void inorder(node* root){
    if(root==NULL){
        return ;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void levelOrderTraversal(node*  root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        if(temp==NULL){// purana level complete traverse ho chuka h
            cout<<endl;// enter maardo 
            if(!q.empty()){// q me elemnt pade hue h-- queue still have some child nodes 
                q.push(NULL);
            }
        }else{
            cout<<temp->data<<" ";
            

            if(temp->left){
                q.push(temp->left);
            }

            if(temp->right){
                q.push(temp->right);
            }
        }
        
    }
}

void preOrder(node* root){
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);
}


void buildFromLevelOrderTraversals(node* &root){
    queue<node*>q;
    int data;
    cout<<"Enter data for root: ";
    cin>>data;
    root= new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        cout<<"Enter the left node for "<<temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData!=-1){
            temp->left= new node(leftData);
            q.push(temp->left);
        }


        cout<<"Enter the right node for "<<temp->data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData!=-1){
            temp->right= new node(rightData);
            q.push(temp->right);
        }
    }

}

int main(){
    
    node* root= NULL;
    
    buildFromLevelOrderTraversals(root);
    levelOrderTraversal(root);
    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1



    // creating a tree
    // root= buildTree(root);

    // //level order
    // // levelOrderTraversal(root);
    // cout<<"Inorder Traversals: "<<endl;
    // inorder(root);
    // cout<<"Preorder Traversals: "<<endl;
    // preOrder(root);

    //data
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 


    //USING SEPERATORS==>TABHI EK LINE ME AAYEGA  

    return 0;
}
