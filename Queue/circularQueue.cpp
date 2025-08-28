#include<iostream>
using namespace std;

class circularQueue{

    public:
    int *arr;
    int front;
    int rear;
    int size;

    circularQueue(int size){
        this->size = size;
        front = -1;
        rear = -1;
        arr = new int[size];
    }

    void push(int n){
        //check if queue is full
        if((front == 0 && rear == size-1) || ((rear+1)%size == front)){
            cout<<"queue is full"<<endl;
        }

        //if rear is just behind the front element then also full
        
        if(front == -1){ //means nothing to remove --- already empty
            rear = front = 0;
        }
        else{
            rear = (rear+1)%size;  //move automatically to the first index after last idx
        }
        arr[rear] = n;
        
    }


    void pop(){
        //check if queue is empty
        if(front == -1){  //nothing to pop -- nothing pushed
            cout<<"Queue is empty"<<endl;
        }


        if(front == rear){ //single element exists
        front = rear = -1; //resetting queue
        }
        else{
            front = (front+1)%size; //increasing the front by 1 means removing 1 element
        }
    }

    int getFront(){
        if(!isEmpty()){
            int ans = arr[front];
            return ans;        
        }
        return -1;

    }

    bool isEmpty(){
        if(front == -1) return true;
        return false;
    }
};

int main(){
    circularQueue q(3);

    q.push(1);
    q.push(2);
    q.push(3);

    cout<<q.getFront()<<endl;
    q.pop(); //pop 1
    cout<<q.getFront()<<endl;
    cout<<q.isEmpty()<<endl;
    q.pop(); //pop2 
    q.pop(); //pop3
    cout<<q.isEmpty()<<endl;
}