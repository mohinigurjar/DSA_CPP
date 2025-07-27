#include<iostream>
using namespace std;

//create node
class Node{
    public: 

    int data;
    Node* next;

    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }
};

void insertAtHead(Node* &head, int d){
    //creating the node which we want to insert
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void print(Node* & head){
    //we wnat to traverse the array without changing our head - head should be the first node
    Node* temp = head;

    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}


int main(){
    Node* node1 = new Node(10);
    //making node1 our head
    Node* head = node1;
    print(head);

    insertAtHead(head, 20);
    print(head);
    return 0;
}