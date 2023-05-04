#include<iostream>
using namespace std;

static int counter=0;
int main()
{
    int m,n;
    cout<<"ENTER THE DIMENSIONS : ";
    cin>>m>>n;
    int matrix1[m][n],matrix2[n][m],result[m][m];

    cout<<"Enter the elements of matrix 1 : ";
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
        {
            cout<<"[ "<<i+1<<" ]"<<"[ "<<j+1<<" ] : ";
            cin>>matrix1[i][j];
        }
    }

     cout<<"Enter the elements in matrix-2 :"<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        {
            cout<<"[ "<<i+1<<" ]"<<"[ "<<j+1<<" ] : ";
            cin>>matrix2[i][j];
        }
    }


    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++){

            result[i][j]=0;
            for(int k=0;k<n;k++)
            {
                result[i][j]+=matrix1[i][k]*matrix2[k][j];

                counter++;
            }
        }
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++)
        cout<<result[i][j]<<" ";

        cout<<endl;

    }
    cout<<"COUNTER : "<<counter<<endl;
    cout<<"PARTH PATEL 19DCS098"<<endl;
    return 0;
}