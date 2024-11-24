#include<iostream>
using namespace std;

void printArray(int arr[], int len) {
    for(int i = 0; i < len; i++) {
        cout<< arr[i] << " ";
    }
    cout<<endl;
}

void merge(int arr[], int s, int mid, int e) {
    int* temp = new int[e - s + 1];
    int i = s;
    int j = mid + 1;
    int k = 0;
    while(i <= mid && j <= e) {
        if(arr[i] < arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while(i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while(j <= e) {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for(k = 0, i = s; k <= e - s; k++, i++) {
        arr[i] = temp[k];
    }
    delete[] temp;
}

void mergeSort(int arr[], int s, int e) {
    if(s >= e) return;
    int mid = s + (e - s) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid+1, e);
    merge(arr, s, mid, e);
}

int main() {
    int arr[] = {9, 8, 7, 6, 5};
    int len = sizeof(arr)/sizeof(arr[0]);
    printArray(arr,len);
    mergeSort(arr, 0, len-1);
    printArray(arr,len);
    return 0;
}