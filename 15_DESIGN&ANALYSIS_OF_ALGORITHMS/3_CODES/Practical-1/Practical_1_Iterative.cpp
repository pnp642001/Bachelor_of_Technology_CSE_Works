#include<iostream>
using namespace std;
int main()
{
    int counter=0;
    double number;
    cout<<"Enter the number : "; // INPUT
    cin>>number;

    double fact=1; 

    for(double i=number;i>=1;i--){  //MAIN LOGIC
        fact*=i;
        counter++; 
    }

    cout<<fact<<endl;
    cout<<"Counter : "<<counter<<endl;

    cout<<endl;

    cout<<"PARTH PATEL "<<"19DCS098"<<endl;

    return 0;
}