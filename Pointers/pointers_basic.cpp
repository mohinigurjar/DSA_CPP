#include<iostream>
using namespace std;

int main(){
	int a = 5;
	
	int *p1 = &a;
	cout<<"a = "<<a<<endl;
	cout<<"ptr = address ="<<p1<<endl;
	cout<<"&a = "<<&a<<endl;
	cout<<"*p1 = value ="<<*p1<<endl;
	cout<<"&p1 = "<<&p1<<endl;
	
	char alphabet = 'a';
	char *p2 = &alphabet;
	cout<<"address of alphabet = "<<p2<<endl;
	cout<<"value of alphabet = "<<*p2<<endl;
	
	double d = 4.3;
	double *p3 = &d;
	cout<<p3<<endl;
	cout<<*p3<<endl;
	
	cout<<sizeof(p1)<<endl;
	cout<<sizeof(p2)<<endl;
	cout<<sizeof(p3)<<endl;
	
	int *p4 = 0;
	cout<<p4<<endl;
//	cout<<*p4<<endl;
	
	(*p1)++;
	cout<<a<<endl;
	cout<<p1<<endl;
	
	//copying a ptr
	int *q1 = p1;
	cout<<q1<<endl;
	cout<<*q1<<endl;
	
	
	double *p5 = &d;
	cout<<p5<<endl;
	cout<<*p5<<endl;
	
	
	p1 = p1+1;//increases the stored address by 4 bytes because it was an integer pointer, if it was a double pointer than it must have increased by 8 bytes
	cout<<p1<<endl;
	cout<<*p1<<endl;
	
}
