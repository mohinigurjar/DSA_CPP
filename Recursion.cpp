#include<iostream>
using namespace std;

int factorial(int n){
	//base case
	if(n==0)
	 return 1;
	 
	//Recursive Relation
	int smallerProblem = factorial(n-1);
	int biggerProblem = n * smallerProblem;
	
	return biggerProblem;
}

int power(int n){
	//base case
	if(n==0)
	 return 1;
	 
	//Recursive Relation
	int sp = power(n-1);
	int bp = 2 * sp;
	return bp;
}

int count(int n){
	//base case
	if(n==1){
		return 1;
	}
	//Recursive Relation
	cout<<n;
	count(n-1);
}
int main(){
	int n;
	cin>>n;
	
	int ans = factorial(n);
	cout<<ans<<endl;
	
	int pow = power(n);
	cout<<pow<<endl;
	
	int counting = count(n);
	cout<<counting<<endl;
	
	return 0;
	 
}
