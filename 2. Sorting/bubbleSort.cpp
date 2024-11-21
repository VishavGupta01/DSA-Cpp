#include<iostream>
using namespace std;

void printArray(int arr[], int len) {
    for(int i = 0; i < len; i++) {
        cout<< arr[i] << " ";
    }
    cout<<endl;
}

void bubbleSort(int arr[], int len) {
    for(int i = 0; i < len; i++) {
        int cnt = 0;
        for(int j = 0; j < len - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                cnt++;
            }
        }
        if(cnt == 0) break;
    }
}

int main() {
    int arr[] = {3,2,6,1,2,10,7};
    int len = sizeof(arr)/sizeof(arr[0]);
    printArray(arr,len);
    bubbleSort(arr,len);
    printArray(arr,len);
    return 0;
}