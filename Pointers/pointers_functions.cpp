#include<iostream>
using namespace std;

void print(int *p){
	cout<<*p<<endl;
}

void update(int *p){
//	p = p+1;
//	cout<<"p inside function   "<<p<<endl; //p give the updated address
    *p = *p+1;
}

int printSum(int arr[], int n){ //inplace of arr[] we can write *arr
//internally this arr is not actually array instead it is a pointer which holds the address of the first element of array
	int sum = 0;
	cout<<"size of arr is "<<sizeof(arr)<<endl; //here array size should be 20 but it is 8 because arrays are always passed as pointers
	for(int i=0; i<n; i++){
		sum += arr[i];
	}
		return sum;
}


int main(){
	
	int val = 5;
	int *p = &val;
	
	print(p); //can't write here * for getting  value but we can write in print function
	
	
//	cout<<"Before   "<<p<<endl;
//	update(p);
//	cout<<"After    "<<p<<endl; //p will not give updated address here
	
	cout<<"Before   "<<*p<<endl;
	update(p);
	cout<<"After    "<<*p<<endl; //p will give updated value here
	
	int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8};
	cout<<"Sum is "<<printSum(arr+5, 3)<<endl; //tis is the benefit of array being passed as a pointer because  we can use its particular part according to us as here we print sum of last 3 elements only
	
	
	
	return 0;	
}
