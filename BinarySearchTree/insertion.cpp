#include<iostream>
#include<queue>
#include<stack>
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
    q.push(NULL); //for separating tthe levels

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

vector<int> preorder(Node* root){
    stack<Node*> st;
    st.push(root);
    vector<int> pre;

    while(!st.empty()){
        Node* temp = st.top();
        st.pop();

        pre.push_back(temp->data);
        if(temp->right) st.push(temp->right);
        if(temp->left) st.push(temp->left);
    }

    return pre;
}

vector<int> inorder(Node* root){
    stack<Node*> st;
    vector<int> v;
    Node* temp = root;

    while(temp != NULL || st.empty()==false){
        while(temp!=NULL){
            st.push(temp);
            temp = temp->left;
        } 
        temp = st.top();
        st.pop();

        v.push_back(temp->data);

        temp = temp->right; 
    }
    return v;

}

vector<int> postorder(Node* root){ //LRN <-> NRL(similar to pre)
    stack<Node*> s1;
    stack<Node*> s2;
    vector<int> v;
    
    s1.push(root);
    
    while(!s1.empty() ){
        Node*temp = s1.top();
        s1.pop();
        
        s2.push(temp);
        
        if(temp->left)s1.push(temp->left);
        if(temp->right) s1.push(temp->right);
    }
    
    while(!s2.empty()){
        Node* temp = s2.top();
        s2.pop();
        v.push_back(temp->data);
    }
    
    return v;
    
}

int minVal(Node* root){
    if(root == NULL) return -1;
    Node* temp = root;

    while(temp->left!=NULL){
        temp = temp->left;
    }

    return temp->data;
}

int maxVal(Node* root){
    if(root == NULL) return -1;
    Node* temp = root;

    while(temp->right!=NULL){
        temp = temp->right;
    }
    return temp->data;
}

Node* deleteFromBST(Node* root, int val){
    //base case
    if(root == NULL) return root;

    if(root->data == val){
        //0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        //1 child

        //left child
        if(root->left!=NULL && root->right == NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }
        //right child
        if(root->right != NULL && root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        //2 child
        if(root->left != NULL && root->right != NULL){
            int mini = minVal(root->right);
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }

    }
    else if(root->data > val){
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else{
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}

int main() {
    Node* root = NULL;
    cout<<"Enter the data to create BST"<<endl;
    takeInput(root);
    cout<<endl;

    printBST(root);

    cout<<"Inorder"<<endl;
    vector<int> ans = inorder(root);
    for(int val : ans){
        cout<<val<<" ";
    }
    cout<<endl;
    
    cout<<"Preorder traversal"<<endl;
    vector<int> ans1 = preorder(root);
    for(int val : ans1){
        cout<<val<<" ";
    }
    cout<<endl;
    
    cout<<"Postorder traversal"<<endl;
    vector<int> ans2 = postorder(root);
    for(int val : ans2){
        cout<<val<<" ";
    }
    cout<<endl;

    int mini = minVal(root);
    cout<<"MINIMUM VALUE "<<mini<<endl;

    int maxi = maxVal(root);
    cout<<"MAXIMUM VALUE "<<maxi<<endl;

    deleteFromBST(root, 70);
    
    printBST(root);

    


}