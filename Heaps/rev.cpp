#include<iostream>
using namespace std;

class Heap{
    public:

    int arr[100];
    int size = 0;

    Heap(){
        arr[0] = -1;
        size = 0;
    }


    void insert(int value){
        //inserting a node

        //1. insert at end
        size = size + 1;
        int index = size;
        arr[index] = value;


        //check the max heap property -- find the parent of newly added node and check the max heap property for that
        while(index > 1){
            int parent = index/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }else{
                return;
            }
        }
    }


    //printing the max heap array
    void print(){
        for(int i=1; i<=size; i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }


    //delete root node from heap
    void deleteFromHeap(){
        //interchanging the root node with the last node
        arr[1] = arr[size];
        //decreasing the size means deleting the node
        size--;

        //check the first node max heap property
        int i = 1;
        while (i < size){
            int left = 2*i;
            int right = 2*i+1;

            if(left < size && arr[left] > arr[i]){
                swap(arr[left], arr[i]);
                i = left;
            }
            else if(right < size && arr[right] > arr[i]){
                swap(arr[right], arr[i]);
                i = right;
            }else{
                return;
            }
        }
    }


};

int main(){
    Heap h;

    h.insert(8);
    h.insert(9);
    h.insert(11);
    h.insert(67);
    h.insert(45);

    h.print();

    h.deleteFromHeap();

    h.print();
}
