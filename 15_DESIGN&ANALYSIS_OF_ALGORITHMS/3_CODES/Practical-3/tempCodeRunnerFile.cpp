#include<iostream>
using namespace std;
int counter=0;
void merge(int arr[], int left, int middle, int right){
    int sizeLeft = middle - left +  1;
    int sizeRight = right - middle;
    int leftArray[sizeLeft], rightArray[sizeRight];
    for(int i=0;i<sizeLeft;i++){
        leftArray[i] = arr[left + i];
    }

    for(int i=0;i<sizeRight;i++){
        rightArray[i] = arr[middle+1+i];
    }
    int i=0;
    int j=0;
    int k=left;
    while(i<sizeLeft && j< sizeRight){
        if(leftArray[i] <= rightArray[j]){
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }
    while(i<sizeLeft){
        arr[k] = leftArray[i];
        i++;
        k++;
    }
    while(i<sizeRight){
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left,int right){
    counter++;
    if (right > left){
        int middle = (left + right) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle+1, right);
        merge(arr, left, middle, right);
    }
}


int main(){
    int size;
    cout << "Enter the input size: ";
    cin >> size;

    int arr[size];
    cout << "Enter the values of array: "<< endl;
    for(int i=0;i<size;i++){
        cin >> arr[i];
    }

    mergeSort(arr,0,size);

    cout << "The sorted array : "<< endl;
    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
    cout<<"\nCOUNTER: "<<counter<<endl;
    cout<<"PARTH PATEL 19DCS098"<<endl;
}
