#include<iostream>
using namespace std;

static int counter=0;

void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_index;
 
   
    for (i = 0; i < n-1; i++)
    {
       
        min_index = i;
        for (j = i+1; j < n; j++){
            counter++;
        if (arr[j] < arr[min_index])
            min_index = j;
        }
 
        // Swap the found minimum element with the first element
        swap(&arr[min_index], &arr[i]);
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

    selectionSort(arr,size);
    printArray(arr,size);

     cout<<"COUNTER: "<<counter<<endl;
    cout<<endl;
    cout<<"PARTH PATEL 19DCS098"<<endl;

    return 0;
}