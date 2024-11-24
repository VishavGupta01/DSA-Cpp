#include<iostream>
using namespace std;

void printArray(int arr[], int len) {
    for(int i = 0; i < len; i++) {
        cout<< arr[i] << " ";
    }
    cout<<endl;
}

void selectionSort(int arr[], int len) {
    for(int i = 0; i < len-1; i++) {
        int minIdx = i;
        for(int j = i+1; j < len; j++) {
            if(arr[minIdx] > arr[j]) {
                minIdx = j;
            }
        }
        if(minIdx != i) {
            swap(arr[minIdx], arr[i]);
        }
    }
}

int main() {
    int arr[] = {3,2,6,1,2,10,7};
    int len = sizeof(arr)/sizeof(arr[0]);
    printArray(arr,len);
    selectionSort(arr,len);
    printArray(arr,len);
    return 0;
}