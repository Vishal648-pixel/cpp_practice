//
// Created by vishal on 22/09/26.
//
#include <iostream>
using namespace std;\

#include <iostream>
using namespace std;

void selectionSort(int arr[], int n){
    for(int i = 0; i < n-1; i++){
        int minIndex = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[i],arr[minIndex]);

    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout<<arr[i]<<" ";
    }
}

int main() {
    int arr[7]={10,4,65,32,0,2,-4};
    int n=sizeof(arr)/4;
    selectionSort(arr, n);
    printArray(arr, n);
}
