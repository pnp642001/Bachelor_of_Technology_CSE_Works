#include<iostream>
using namespace std;

int BNFCOEF(int n, int k)
{
   
    if (k == 0 || k == n){
        return 1;
    }

   
    return BNFCOEF(n - 1, k - 1) +
                BNFCOEF(n - 1, k);
}
int main()
{
    int n,k;
    
    cout<<"ENTER THE VALUE OF n AND k : ";
    cin>>n>>k;
    cout<<"BINOMIAL COEFFIECIENT : " <<BNFCOEF(n,k)<<endl;
    cout<<endl;
    cout<<"PARTH PATEL\n19DCS098"<<endl;        
    return 0;
}
