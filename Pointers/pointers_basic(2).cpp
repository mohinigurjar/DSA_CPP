#include<iostream>
using namespace std;

int main(){
	//array pointers
	
	int arr[10]={10,20,30,40};
//	cout<<arr<<endl;  //gives first location address
//	cout<<&arr[0]<<endl;
//	cout<<arr[0]<<endl;
//	cout<<*arr<<endl;
//	cout<<*arr + 1<<endl;
//	cout<<&arr[0] + 1<<endl;
//	cout<<*(arr)+1<<endl;
//    cout<<arr[2]<<endl;
//	cout<<*(arr+2)<<endl;
//	cout<<2[arr]<<endl;
//	cout<<*(2+arr)<<endl;
//	cout<<*arr<<endl;

    
    
//    int *p = &arr[0];
//    cout<<p<<endl;
//    cout<<sizeof(p)<<endl;
//    cout<<sizeof(arr)<<endl;
//    cout<<sizeof(*p)<<endl; //size of the element stored at first location that is integer size
//    cout<<sizeof(&p)<<endl<<endl;
//	
//	
//	int arr2[10] = {0};
//	int *q = &arr2[0];
//	
//	cout<<q<<endl; // address of first array block which is stored in q
//	cout<<&q<<endl; // address of the q block
//	cout<<q+1<<endl; // address of second array block which is stored in q
//	cout<<*q+1<<endl; //*q was 0 so +1 gives 1
//	cout<<&q+1<<endl;  //gives the value of address of q + 8Bytes..because sizeof ptr is 8 bytes
//	
	
	
	//for character arrays
//	cout function is differently implemented for int array and character array
	char ch[6] = "abcde";
//	cout<<ch<<endl; //for arrays tis case is different as it will give the location of first array element and here it gives the elements of character array
//	
	char *c = &ch[0];
	cout<<c<<endl;
	
//	char temp = 'z';
//	char *p = &temp;
//	cout<<p<<endl; //it will not stop until it find null character..so it will print NOT ONLY z but also some extra characters
//	
}
