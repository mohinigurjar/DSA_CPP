#include<iostream>
using namespace std;

class Stack{
    public: //access specifier
        
        //data members
        int top;
        int *arr;
        int size;

    Stack(int size){
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int val){
        //checking if stack have empty space 
        if(size-top > 1){
            top++;
            arr[top] =  val;
        }
        else{
            cout<<"Stack overflow"<<endl;
        }

    }

    void pop(){
        //if stack is not empty
        if(top >= 0){
            top--;
        }
        else{
            cout<<"Stack underflow"<<endl;
        }
    }

    int peek(){
        if(top >= 0){
            return arr[top];
        }
        else{
            cout<<"Stack is empty"<<endl;
            return -1;
        }
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }

};

int main(){

    Stack st(5);

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    
    if(st.isEmpty()){
        cout<<"stack is empty"<<endl;
    }
    else{
        cout<<"stack is not empty"<<endl;
    }

    st.pop();
    st.pop();
    st.pop();
    cout<<st.peek()<<endl;


    return 0;

}