#include<iostream>
using namespace std;

static int counter=0;

void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}
void bubbleSort(int arr[],int size){
    bool swapped;

    for(int i=0;i<size-1;i++)
    {
        swapped=false;

        for(int j=0;j<size-1-i;j++)
        {
            counter++;
            if(arr[j]>arr[j+1])
            {
                swap(&arr[j],&arr[j+1]);
                swapped=true;
            }
        }

        if(swapped==false)
        break;
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

    bubbleSort(arr,size);
    printArray(arr,size);

    cout<<"COUNTER: "<<counter<<endl;
    cout<<endl;
    cout<<"PARTH PATEL 19DCS098"<<endl;

    return 0;
}