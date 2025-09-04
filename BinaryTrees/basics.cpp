#include<iostream>
#include<queue>
#include<stack>
#include<vector>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    
    node(int d){
        this->data = d;
        this->left = left;
        this->right = right;
    }
};

node* buildTree(node* root){
    cout<<"Enter data"<<endl;
    int data;
    cin>>data;
    
    if(data == -1) return nullptr;
    
    root = new node(data);
    
    cout<<"Enter left"<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter right"<<endl;
    root->right = buildTree(root->right);
    
    return root;
}

void levelOrder(node* root){
    queue<node*> q;
    
    q.push(root);
    q.push(nullptr);
    
    while(!q.empty()){
        node* temp = q.front();
        q.pop();
        
        if(temp == nullptr){
            cout<<endl;
            if(!q.empty()){
                q.push(nullptr);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}

vector<int> inorder(node* root){
    stack<node*> st;
    vector<int> v;
    node* temp = root;
    
    while(temp!=nullptr || st.empty() == false){
        while(temp!=nullptr){
            st.push(temp);
            temp = temp->left;
        }
        
     //leftmost node
    temp = st.top();
    st.pop();
    
    v.push_back(temp->data);
    
    temp = temp->right;
        
    }
    
   return v;
    
}

vector<int> preorder(node* root){
    stack<node*> st;
    st.push(root);
    vector<int> v;
    
    while(!st.empty()){
        node* temp = st.top();
        st.pop();
        
        v.push_back(temp->data);
        
        if(temp->right) st.push(temp->right);
        if(temp->left) st.push(temp->left);
    }
    
    return v;
}

vector<int> postorder(node* root){ //LRN <-> NRL(similar to pre)
    stack<node*> s1;
    stack<node*> s2;
    vector<int> v;
    
    s1.push(root);
    
    while(!s1.empty() ){
        node*temp = s1.top();
        s1.pop();
        
        s2.push(temp);
        
        if(temp->left)s1.push(temp->left);
        if(temp->right) s1.push(temp->right);
    }
    
    while(!s2.empty()){
        node* temp = s2.top();
        s2.pop();
        v.push_back(temp->data);
    }
    
    return v;
    
}


//1 2 4 -1 -1 5 -1 -1 3 -1 -1

int main(){
    node* root = nullptr;
    root = buildTree(root);
    
    cout<<"LOT"<<endl;
    levelOrder(root);
    cout<<endl;
    
    // cout<<"Preorder"<<endl;
    // preorder(root);
    // cout<<endl;
    
    // cout<<"Postorder"<<endl;
    // postorder(root);
    // cout<<endl;
    
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
}