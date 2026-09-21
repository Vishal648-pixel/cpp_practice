//
// Created by mca on 21/09/26.
//
#include <iostream>
using namespace std;
void bubble_sort(int arr[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void print_arr(int arr[],int size)
{
    for (int i=0;i<=size-1;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int arr[]={64,87,99,35,24,76,12,0,84};
    int size=sizeof(arr)/4;
    cout<<"size :"<<size<<endl;
    cout<<"Before sorting :";
    print_arr(arr,size);
    cout<<"\n";
    bubble_sort(arr,size);

    cout<<"After sorting :";
    print_arr(arr,size);
    return 0;

}