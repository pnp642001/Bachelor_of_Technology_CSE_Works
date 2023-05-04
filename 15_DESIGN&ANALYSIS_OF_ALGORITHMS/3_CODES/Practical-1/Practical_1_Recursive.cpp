#include<iostream>
using namespace std;

static int counter=0;
int factorial(int number){
    if(number==1){
        counter++;
        return 1;
    }

    else{
        counter++;
        return number*factorial(number-1);
    }
}

int main()
{
    int number;
    cout<<"Enter the number : ";
    cin>>number;

    cout<<factorial(number)<<endl;

    cout<<"COUNTER : "<<counter<<endl;

    cout<<endl;
    cout<<"PARTH PATEL"<<"19DCS098"<<endl;
    return 0;
}