//--TODO : Write iterative functions for preorder and postorder traversal and reverse LOT

#include<iostream>
#include<queue>
using namespace std;

//creating our tree
class node{
    //public access specifier
    public:
    int data;
    node* left;
    node* right;
    
    //constructor
    node(int d){
        this->data = d;
        this->left = left;
        this->right = right;
    }
};

//building the tree
node* buildTree(node* root){
    cout<<"Enter data"<<endl;
    int data;
    cin>>data;
    
    if(data == -1) return NULL;
    
    root = new node(data);
    
    cout<<"Enter data for left child"<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for right child"<<endl;
    root->right = buildTree(root->right);
    return root;
}

//LOT
void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root); //pushing our root node
    q.push(NULL); //marking the end of first level
    
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        
        if(temp == NULL){
            cout<<endl;  //moving to the next line for next level
            if(!q.empty()){
                q.push(NULL);  //pushing NULL to mark the end of the next level
            }
        }
        else{
            //if q->front is some data 
            cout<<temp->data<<" ";
            
            //checking the child nodes of current node and push them to queue
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }    
    }    
}




int main(){
    node* root = NULL;
    root = buildTree(root);
    
    levelOrderTraversal(root);
    
    return 0;
}