#include<iostream>
using namespace std;

void printArray(int arr[], int len) {
    for(int i = 0; i < len; i++) {
        cout<< arr[i] << " ";
    }
    cout<<endl;
}

void insertionSort(int arr[], int len) {
    for(int i = 1; i < len; i++) {
        int temp = arr[i];
        int j = i-1;
        for(;j>= 0; j--) {
            if(arr[j] > temp) {
                arr[j+1] = arr[j];
            } else {
                break;
            }
        }
        arr[j+1] = temp;
    }
}

int main() {
    int arr[] = {3,2,6,1,2,10,7};
    int len = sizeof(arr)/sizeof(arr[0]);
    printArray(arr,len);
    insertionSort(arr,len);
    printArray(arr,len);
    return 0;
}
