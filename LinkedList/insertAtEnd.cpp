#include<iostream>
using namespace std;

class Node{
    public:

    int data;
    Node* next;

    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }
};

void insertAtEnd(Node* &tail, int d){
    //create node to be addded
    Node* temp = new Node(d);

    tail -> next = temp;
    tail = tail -> next;

}

void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main() {
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1; //as now we have only one node , so it is the head and tail both

    print(head);
    insertAtEnd(tail, 20);
    print(head);
    return 0;
}