#include<iostream>>
using namespace std;

short linearSearch(int arr[],short len,short key)
{
    for(short i=0;i<len;i++)
    {
        if(arr[i]==key)
            return i;
    }
    return -1;
}

short binarySearch(int arr[],short len,short key)
{
 short lb=0,ub=len,mid=0;
 while(lb<=ub)
 {
     mid=(lb+ub)/2;
     if(arr[mid]==key)
        return mid;
     else if(arr[mid]<key)
     {
         lb=mid+1;
     }
     else
     {
         ub=mid-1;
     }
 }
 return -1;
}
int main()
{
    int arr[10]={1,4,9,27,29,98,102,133,135,151};
    short key;
    cout<<"Enter the roll number for linear search: ";
    cin>>key;
    short ans1=linearSearch(arr,10,key);

    cout<<"Enter the roll number for binary search: ";
    cin>>key;
    short ans2=binarySearch(arr,10,key);

    cout<<"Result of linear Search: "<<endl;
    if(ans1==-1)
    {
        cout<<"This Roll number has not attended the training program!!"<<endl;
    }
    else
    {
        cout<<"Roll Number : "<<arr[ans1]<<" has attended the training program!!"<<endl;
    }

    cout<<endl;
    cout<<"Result of Binary Search:"<<endl;
     if(ans2==-1)
    {
        cout<<"This Roll number has not attended the training program!!"<<endl;
    }
    else
    {
        cout<<"Roll Number : "<<arr[ans2]<<" has attended the training program!!"<<endl;
    }

    cout<<"PARTH PATEL"<<endl<<"19DCS098"<<endl;

    return 0;

}
