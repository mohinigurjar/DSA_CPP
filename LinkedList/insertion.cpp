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

void insertAtHead(Node* &head, int d){
    Node* temp = new Node(d);

    temp -> next = head;
    head = temp; //make head pointing to first node
}

void insertAtTail(Node* &tail, int d){
    Node* newNode = new Node(d);

    if(tail -> next == NULL){
        tail -> next = newNode;
    }

    tail = newNode;
}
void insertAtPosition(Node* &head, Node* &tail, int position, int d){
    if(position == 1){ //solves the first position issue
        insertAtHead(head, d);
        return;
    }
    Node* temp = head;
    Node* nodeToInsert = new Node(d);
    int cnt = 1; //current node position 

    while(cnt < position-1){
        temp = temp -> next;
        cnt++;
    }

    //inserting at last
    if(temp -> next == NULL){
        insertAtTail(tail, d);
        return;
    }

    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}

void print(Node* & head){
    Node* temp = head;

    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;

    print(head);
    insertAtTail(tail, 20);
    print(head);
    insertAtHead(head, 0);
    print(head);
    insertAtTail(tail, 30);
    print(head);

    insertAtPosition(head, tail, 3, 15);
    print(head);

    insertAtPosition(head, tail, 6, 40); //it will insert at last position but will not set tail to point last node
    print(head);

    insertAtPosition(head, tail, 1, 1); // this adds element at second position , coz we are starting from the first position itself
    print(head);

    insertAtTail(tail, 50);
    print(head);

    cout<<head->data<<endl;
    cout<< tail->data <<endl;


}