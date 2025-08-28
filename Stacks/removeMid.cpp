#include<iostream>
#include<stack>
using namespace std;

//Here & before InputStack is very important because without &, a copy of s is made and the modifications happen in that so 
//when we call it in main function s remains same : removeMid(s, count, size) give the same s
//Passing by reference will make the changes to the original stack of our main function
void removeMid(stack<int> &InputStack, int count, int size){ 

    if(count == size/2){
        InputStack.pop();
        return;
    }

    int num = InputStack.top();
    InputStack.pop();
    removeMid(InputStack, count+1, size);
    InputStack.push(num);

}
int main(){
    stack<int> s;
    int count=0;
    
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    // cout<<s.top()<<endl;
    // cout<<s.size()<<endl;
    int size = s.size();

    removeMid(s, count, size);
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    return 0;
}