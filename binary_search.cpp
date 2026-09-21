//
// Created by Vishal on 9/18/2026.
//
#include <iostream>
using namespace std;

void binary_Search(int arr[],int size,int target) {
    int low=0;
    int high=size-1;
    while (low<=high) {
        int mid=(low+high)/2;
        if (arr[mid]==target) {
            cout<<"The target is found on :"<<mid<<endl;
            return;
        }
        else if (target > arr[mid]) {// greater than for right side
            low=mid+1;
        }
        else if (target < arr[mid]) {// less than for left side
            high=mid-1;
        }
    }
}

int main() {
    int arr[]={10,20,30,40,50,60,70,80,90};
    int size=sizeof(arr)/4;
    int target;
    cout<<"Enter target :"<<endl;
    cin>>target;
    binary_Search(arr,size,target);
}
