#include<iostream>
using namespace std;
int counter = 0;
int power(int x, unsigned int y) {
    if (y == 0) 
        return 1;
    else if (y % 2 == 0){
        counter++;
        return power(x, y / 2) * power(x, y / 2);
    }
    else{
        counter++;
        return x * power(x, y / 2) * power(x, y / 2);
    }
}
int main() {
    int x;
    unsigned int y;

    cout<<"Enter the value of X : ";
    cin>>x;
    cout<<"Enter the value of Y : ";
    cin>>y;

    cout<<"X ^ Y : "<<power(x,y)<<endl;
    cout<<"COUNTER : "<<counter<<endl;

    cout<<"PARTH PATEL\n19DCS098"<<endl;

    return 0;

}