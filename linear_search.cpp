#include <iostream>
using namespace std;
void linear_search(int arr[],int size,int target) {
    for (int i=0;i<size;i++) {
        if(arr[i]==target) {
            cout<<"The Target is found at :"<<i<<endl;
        }
    }
}

int main() {
    int arr[]={57,78,99,65,48,25,36,88};
    int size=sizeof(arr)/4;
    for (int x:arr) {
        cout<<x<<" ";
    }
    cout<<"\n";
    int target;
    cout<<"Enter target:";
    cin>>target;
    linear_search(arr,size,target);
}
