#include <iostream>
using namespace std;

class Heap {
    public:
    int arr[100];
    int size;

    Heap() {
        arr[0] = -1;
        size = 0;
    }

    void insert(int d) {
        size++;
        int index = size;
        arr[index] = d;
        while(index > 1) {
            int parent = index / 2;
            if(arr[parent] < arr[index]) {
                swap(arr[parent], arr[index]);
                index = parent;
            } else {
                return;
            }
        }
    }

    void deleteRoot() { // TC: O(log n)
        if(size == 0) {
            cout<<"Heap is Empty!"<<endl;
            return;
        }
        arr[1] = arr[size];
        size--;
        int i = 1;
        while(i < size) {
            int leftIdx = i*2;
            int rightIdx = i*2 + 1;
            int largest = i;
            if(leftIdx <= size && arr[leftIdx]>arr[largest]){
                largest = leftIdx;
            }
            if(rightIdx<=size && arr[rightIdx]>arr[largest]){
                largest = rightIdx;
            }

            if(largest != i) {
                swap(arr[i], arr[largest]);
                i = largest;
            } else {
                return;
            }
        }
    }

    void print() {
        for(int i = 1; i <= size; i++) {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

void heapify(int arr[], int i, int size) {
    int largest = i;
    int left = i * 2;
    int right = i * 2 + 1;
    if( left <= size && arr[left] > arr[largest]) {
        largest = left;
    }
    if(right <= size && arr[right] > arr[largest]) {
        largest = right;
    }

    if(largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, largest, size);
    }
}

void heapSort(int arr[], int size) { //TC: O(n log n)
    while(size > 1) {
        swap(arr[size], arr[1]);
        size--;

        heapify(arr, 1, size);
    }
}

int main() {

    Heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deleteRoot();
    h.print();

    //Building a MaxHeap from an Array
    int arr1[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for(int i = n/2; i > 0; i--) {
        heapify(arr1, i, n);
    }
    cout<<endl<<"Printing the Heap"<<endl;
    for(int i = 1; i <= n; i++) {
        cout<<arr1[i]<<" ";
    }
    cout<<endl;

    //HeapSort
    heapSort(arr1, n);
    cout<<endl<<"Printing the Sorted Array: "<<endl;
    for(int i = 1; i <= n; i++) {
        cout<<arr1[i]<<" ";
    }
    cout<<endl;

    return 0;
}