//--TODO : Write the function for height

#include<iostream>
using namespace std;

class node{
    //access specifier
    public:
    //data members
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


node* buildTree(node* root){
    cout<<"Enter the data"<<endl;
    int data;
    cin>>data;

    if(data == -1) return nullptr;

    cout<<"Enter left child"<<endl;
    root->left = buildTree(root->left);

    cout<<"Enter right child"<<endl;
    root->right = buildTree(root->right);

    return root;
}

int main(){
    node* root = nullptr;
    root = buildTree(root);
}