#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertToBST(Node* &root, int d){
    if(root == NULL) {
        root = new Node(d);
        return root;
    }

    if(d < root->data){
        insertToBST(root->left, d);
    }
    else{
        insertToBST(root->right, d);
    }

    return root;

}

void takeInput(Node* &root){
    int d;
    cin>>d;

    while(d != -1){
        insertToBST(root, d);
        cin>>d;
    }
}

void printBST(Node* root){
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";

            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}

int main() {
    Node* root = NULL;
    cout<<"Enter the data to create BST"<<endl;
    takeInput(root);
    cout<<endl;

    printBST(root);


}