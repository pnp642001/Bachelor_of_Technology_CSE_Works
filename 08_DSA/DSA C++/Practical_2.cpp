#include<iostream>
using namespace std;

void display(float arr[],int len)
{

    for(int i=0;i<len;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
void Swap(float *x,float *y)
{
     float tmp;
     tmp=*x;
     *x=*y;
     *y=tmp;
}
void bubbleSort(float arr[],int len,short order)
{
    if(order==1){
    for(int i=0;i<len-1;i++)
    {
        for(int j=0;j<len-1-i;j++)
        {

            if(arr[j]>arr[j+1])
                {
                   Swap(&arr[j],&arr[j+1]);
                }
        }
    }
    }
    else if(order==0)
    {
            for(int i=0;i<len-1;i++)
    {
        for(int j=0;j<len-1-i;j++)
        {

            if(arr[j]<arr[j+1])
                {
                   Swap(&arr[j],&arr[j+1]);
                }
        }
    }

    }
}


void insertionSort(float arr[], int len,short order)
{
    int i,j;
    float key;
    if(order==1){
    for (i = 1; i < len; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    }

    else if(order==0)
    {
        for (i = 1; i < len; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j]<key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    }
}

int main()
{

    float arr[]={7.4,1.4,2.4,3.4,6.4,4.4,5.4,7.3,5.3,6.3,2.3,1.3,3.3,4.3,6.2,7.2,5.2,4.2,1.2,2.2,3.2,7.1,5.1,6.1,2.1,1.1,3.1,4.1};
    int len=sizeof(arr)/sizeof(arr[0]);
    cout<<"Insertion Sort in Ascending Order : "<<endl;
    insertionSort(arr,len,1);
    display(arr,len);
    cout<<"---------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"Insertion Sort in Descending Order : "<<endl;
    insertionSort(arr,len,0);
    display(arr,len);
    cout<<"---------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"Bubble Sort in Ascending Order : "<<endl;
    bubbleSort(arr,len,1);
    display(arr,len);
    cout<<"---------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<"Bubble Sort in Descending Order : "<<endl;
    bubbleSort(arr,len,0);
    display(arr,len);
    cout<<"---------------------------------------------------------------------------------------------------------------------"<<endl;

    cout<<"PARTH PATEL\n19DCS098"<<endl;
    return 0;

}
