#include <bits/stdc++.h>
using namespace std;
void greedyApproach(int sum,int length,int coins[])
{
    int answer[sum];
    int i=0,count=0;

    for(i=length-1;i>=0;i--)
    {
        while(sum>=coins[i])
        {
            sum=sum-coins[i];
            answer[count]=coins[i];
            count++;
        }
    }
    cout<<"REQUIRED NUMBER OF COINS : "<<count<<endl;
    cout<<"THERE COIN VALUES : "<<endl;
    for(i=0;i<count;i++)
        cout<<answer[i]<<" ";
    cout<<endl;
}
int main()
{
    int n,i,sum;
    cout<<"ENTER TOTAL NUMBER OF COINS : ";
    cin>>n;
    int coins[n];
    cout<<"ENTER THE VALUES OF COINS : ";
    for(i=0;i<n;i++)
        cin>>coins[i];
   sort(coins,coins+n);
    cout<<"Enter the final sum of coins : ";
    cin>>sum;
    greedyApproach(sum,n,coins);
    cout<<"PARTH PATEL\n19DCS098"<<endl;
    return 0;
}
