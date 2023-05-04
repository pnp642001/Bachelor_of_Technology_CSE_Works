#include<iostream>
using namespace std;

static int counter=0;
int main()
{
    int m,n;
    cout<<"Enter the dimensions of matrix : ";
    cin>>m>>n;
    int matrix1[m][n],matrix2[m][n],sum[m][n];

    cout<<"Enter the elements in matrix-1 :"<<endl;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
        {
            cout<<"[ "<<i+1<<" ]"<<"[ "<<j+1<<" ] : ";
            cin>>matrix1[i][j];
        }
    }

     cout<<"Enter the elements in matrix-2 :"<<endl;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
        {
            cout<<"[ "<<i+1<<" ]"<<"[ "<<j+1<<" ] : ";
            cin>>matrix2[i][j];
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
        sum[i][j]=matrix1[i][j]+matrix2[i][j];

        counter++;}
    }

    cout<<"The addition of two matrix : "<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<sum[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
    cout<<"COUNTER : "<<counter<<endl;
    cout<<"PARTH PATEL 19DCS098"<<endl;
    return 0;


}