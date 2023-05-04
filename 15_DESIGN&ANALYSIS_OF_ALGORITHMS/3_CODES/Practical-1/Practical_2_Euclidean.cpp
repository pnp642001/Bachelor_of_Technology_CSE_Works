#include<iostream>
using namespace std;

static int counter=0;
int gcd(int a,int b){

    if(a==0) {
        counter++;
        return b;
    }

    else {
        counter++;
        return gcd(b%a,a);
    }
}
int main()
{
    int a,b;

    cout<<"Enter the numbers : (b>a) : ";
    cin>>a>>b;

    cout<<"GCD : "<<gcd(a,b)<<endl;

    cout<<"COUNTER : "<<counter<<endl;

    cout<<endl;

    cout<<"PARTH PATEL "<<"19DCS098"<<endl;

    return 0;
}