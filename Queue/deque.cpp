#include<iostream>
using namespace std;

//DOUBLY ENDED QUEUE

//deque allows 4 operations
//--push_back
//--pop_back
//--push_front
//--pop_Front

class deque{

    public:
    int *arr;
    int front;
    int rear;
    int size;

    deque(int size){
        this->size = size;
        front = -1;
        rear = -1;
        arr = new int[size];
    }

    bool push_front(int n){
        //check if queue is full
        if((front == 0 && rear == size-1) || ((rear+1)%size == front)){
            cout<<"Queue is full"<<endl;  
            return false;   
        }
        if(front == -1){ //nothing pushed
            front = rear = 0;
        }
        else{
            front = (front-1 + size)%size; //for safe circular logic
        }

        arr[front] = n;
        return true;    
    }


    bool pop_front() {
        //check if queue is empty
        if(front == -1){
            cout<<"Queue is empty"<<endl;
            return false;
        }

        if(front == rear){ //single element exists in the queue
            front = rear = -1;
        }
        else{
            front = (front+1)%size; //moving front one step to remove element
        }

        return true;
        
    }

    bool push_rear(int n){
        //check if stack is already full
        if(isFull()){
            cout<<"Queue is full"<<endl;
            return false;
        }

        if(front == -1){ //no elements pushed
            rear = front = 0;
        }

        else{
            rear = (rear+1)%size; //maintaining circular
        }

        arr[rear] = n;
        return true;

    }


    bool pop_rear(){
         //check if queue is empty
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
            return false;
        }

        if(front == rear){
            front = rear = -1;
        }
        else{
            rear = (rear-1+size)%size; //moving rear backward while popping elements
        }

        return true;

    }

    int getFront(){
        if(isEmpty()){
            return -1;
        }
        else{
            return arr[front];
        }
    }

    bool isEmpty(){
        if(front == -1) return true;
        else return false;
    }

    bool isFull(){
        if((front == 0 && rear == size-1) || ((rear+1)%size == front)){
            return true;
        }
        else{
            return false;
        }
    }

};

int main(){

    deque d(5);
    d.push_front(13);
    d.push_front(14);
    d.push_rear(15);
    d.push_rear(16);  // -- 14 13 15 16

    // cout<<d.getFront()<<endl;
    // d.pop_front();
    // cout<<d.getFront()<<endl;

    // while(!d.isEmpty()){
    //     cout<<d.getFront()<<endl;
    //     d.pop_front();
    // }

    d.pop_rear();
    while(!d.isEmpty()){
        cout<<d.getFront()<<endl;
        d.pop_front();
    }
}