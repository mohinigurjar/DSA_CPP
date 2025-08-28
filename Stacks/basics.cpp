#include<iostream>
#include<stack>
using namespace std;

int main() {
    stack<int> s;
    s.push(2);
    s.push(3); //3 is top
    cout<<"Top element is "<<s.top()<<endl;
    s.pop();
    cout<<"Top element after pop is "<<s.top()<<endl;
    cout<<"Stack is empty "<<s.empty()<<endl;
    cout<<"Size of stack "<<s.size()<<endl;

    return 0;
}