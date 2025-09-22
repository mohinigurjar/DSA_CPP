#include<iostream>
using namespace std;

class Heap{
    public:
    int arr[100];
    int size;

    Heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int val){
        //increase the size
        size = size+1;
        int index = size;

        //add at end
        arr[index] = val;

        //move inserted elt to its correct position
        while(index > 1){
            int parent = index/2;
            
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    //delete the root node
    void deleteFromHeap(){
        if(size == 0) return;
        //swapping tne root node with last element
        swap(arr[size], arr[1]);

        //decrease the size
        size--;

        //move the new root to its correct position
        int i=1;
        while(i < size){
            int left = 2*i + 1;
            int right = 2*i + 2;

            if(left <= size && arr[left] > arr[i]){
                swap(arr[left], arr[i]);
                i = left;
            }
            else if(right <= size && arr[right] > arr[i]){
                swap(arr[right], arr[i]);
                i = right;
            }
            else {
                return;
            }
        }
    }

    void print(){
        for(int i=1; i<=size; i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }

    //position ith node at its correct place
    void heapify(int arr[], int n, int i){
        int largest = i;
        int left = 2*i;
        int right = 2*i + 1;

        if(left <= n && arr[left] > arr[largest]){
            largest = left;
        }
        if(right <= n && arr[right] > arr[largest]){
            largest = right;
        }

        if(largest != i){
            swap(arr[largest], arr[i]);
            heapify(arr, largest, n);
        }
    }

    void heapSort(int arr[], int n){
        int size = n;

        while( size > 1){

            swap(arr[size], arr[1]);
            size--;

            heapify(arr, size, 1);

        }
    }
};


int main(){
    Heap h;

    // int arr[] = {-1, 42, 32, 62, 72, 82};
    // int n = 5;

    h.insert(42);
    h.insert(32);
    h.insert(62);
    h.insert(72);
    h.insert(82);

    h.print();

    h.deleteFromHeap();

    h.print();

     int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;

    for(int i=3; i>0; i--){
        h.heapify(arr, n, i);
    }

    cout<<"PRINTING THE ARRAY NOW"<<endl;
    for(int i=1; i<=n; i++){
        cout<<arr[i]<<" ";
    }cout<<endl;


    h.heapsort(arr, n);
    h.print();
}