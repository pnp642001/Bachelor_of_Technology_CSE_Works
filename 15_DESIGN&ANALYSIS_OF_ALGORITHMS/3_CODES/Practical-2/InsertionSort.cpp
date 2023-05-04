#include<iostream>
using namespace std;

static int counter=0;

void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key)
        {
            counter++;
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[],int size){

    cout<<" The sorted array is : "<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int size;

    cout<<"Enter the size of array : ";
    cin>>size;

    int arr[size];

    cout<<"Enter the elements : ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }

    insertionSort(arr,size);
    printArray(arr,size);

     cout<<"COUNTER: "<<counter<<endl;
    cout<<endl;
    cout<<"PARTH PATEL 19DCS098"<<endl;
    
    return 0;
}