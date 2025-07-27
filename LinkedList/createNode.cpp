#include<iostream>
using namespace std;

//creating class for our LinkedList ka node

class Node{
    //access specifier - public means we can access it outside of the class
    public:
     
    //data members
    int data;
    Node* next;

    //constructor - same name as class - necessary
    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }

};

int main() {

    Node* node1 = new Node(10);
    cout<<node1 -> data<<endl;
    cout<<node1 -> next<<endl;

}