#include<iostream>
using namespace std;

void printArray(int arr[], int len) {
    for(int i = 0; i < len; i++) {
        cout<< arr[i] << " ";
    }
    cout<<endl;
}

int partition(int arr[], int s, int e) {
    int pivot = arr[s];
    int cnt = 0;

    //Finding no of smaller elements than pivot element
    for(int i = s+1; i <= e; i++) {
        if(arr[i] < pivot) cnt++;
    }
    int pivotIdx = s + cnt;
    swap(arr[s], arr[pivotIdx]);
    int i = s, j = e;
    while(i < pivotIdx && j > pivotIdx) {
        while(arr[i] < arr[pivotIdx]) i++;
        while(arr[j] > arr[pivotIdx]) j--;
        if(i < pivotIdx && j > pivotIdx) {
            swap(arr[i], arr[j]);
        }
    }
    return pivotIdx;
}

void quickSort(int arr[], int s, int e) {
    if(s >= e) return;
    int p = partition(arr, s, e);
    quickSort(arr, s, p-1);
    quickSort(arr, p+1, e);
}

int main() {
    int arr[] = {9, 8, 7, 6, 5};
    int len = sizeof(arr)/sizeof(arr[0]);
    printArray(arr,len);
    quickSort(arr, 0, len-1);
    printArray(arr,len);
    return 0;
}