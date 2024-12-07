#include<iostream>
using namespace std;
#define MAX 100

class Heap {
    public:
    int arr[MAX];
    int size;
    Heap() {
        arr[0] = -1;
        size = 0;
    }

    void insert(int d) {
        if(size == MAX) {
            cout<<"Heap OverFlow!"<<endl;
            return;
        }
        size++;
        int idx = size;
        arr[idx] = d;
        while(idx > 1) {
            if(arr[idx/2] < arr[idx]) {
                swap(arr[idx/2], arr[idx]);
                idx = idx/2;
            } else return;
        }
    }

    void deletion() {
        if(size == 0) {
            cout<<"Heap UnderFlow!"<<endl;
            return;
        }
        arr[1] = arr[size];
        size--;
        int idx = 1;
        while(idx < size) {
            int leftChild = 2*idx;
            int rightChild = 2*idx + 1;
            if(leftChild < size && arr[idx] < arr[leftChild]) {
                swap(arr[leftChild] , arr[idx]);
                idx = leftChild;
            } else if(rightChild < size && arr[idx] < arr[rightChild]) {
                swap(arr[rightChild] , arr[idx]);
                idx = rightChild;
            } else return;
        }
    }

    void print() {
        for(int i = 1; i <= size; i++) {
            cout<<arr[i]<<" ";
        } cout<<endl;
    }
};

void heapifyRec(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;
    if(left <= n && arr[largest] < arr[left]) {
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]) {
        largest = right;
    }
    if(largest != i) {
        swap(arr[largest], arr[i]);
        heapifyRec(arr, n, largest);
    }
}

void heapifyItr(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;
    while(true) {
        if(left <= n && arr[largest] < arr[left]) {
            largest = left;
        }
        if(right <= n && arr[largest] < arr[right]) {
            largest = right;
        }
        if(largest != i) {
            swap(arr[largest], arr[i]);
            i = largest;
            left = 2*i;
            right = 2*i + 1;
        } else break;
    }
}

void heapSort(int arr[], int n) {
    while(n > 1) {
        swap(arr[n], arr[1]);
        n--;
        heapifyItr(arr, n , 1);
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
    h.deletion();
    h.print();

    cout<<"Heapify Fxn (Recursion): "<<endl;
    int arr[6] = {-1, 54, 53, 55, 52, 50};
    int n = 5;
    for(int i = n/2; i > 0; i--) {
        heapifyRec(arr, n, i);
    }
    for(int i = 1; i <= n; i++) {
        cout<<arr[i]<<" ";
    } cout<<endl;

    cout<<"Heapify Fxn (Iterative): "<<endl;
    int arr1[6] = {-1, 54, 53, 55, 52, 50};
    int n1 = 5;
    for(int i = n1/2; i > 0; i--) {
        heapifyItr(arr1, n1, i);
    }
    for(int i = 1; i <= n1; i++) {
        cout<<arr1[i]<<" ";
    } cout<<endl;

    cout<<"HeapSort: "<<endl;
    heapSort(arr1, n1);
    for(int i = 1; i <= n1; i++) {
        cout<<arr1[i]<<" ";
    } cout<<endl;

    return 0;
}