#include<iostream>
using namespace std;

class Queue{
    //access specifier
    public: 

    //data members
    int * arr;
    int size;
    int front; //used to pop elements
    int rear; //used to push elements

    //constructor
    Queue(){
        size = 100001;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void push(int n){
        //check if stack is full
        if(rear == size-1){
            cout<<"Queue is full"<<endl;
        }
        else{
            arr[rear++] = n;
        }
    }

    bool isEmpty(){
        if(front == rear) return true;
    }

    int frontElement(){
        if(isEmpty()){
            cout<<"Empty queue"<<endl;
        }
        else{
            return arr[front];
        }
    }

    void pop(){
        //check if stack is empty
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
        }
        else{
            front++;
        }

    }

};

int main(){
    Queue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout<<q.isEmpty()<<endl;
    while(!q.isEmpty()){
        cout<<q.frontElement()<<endl;
    }
}