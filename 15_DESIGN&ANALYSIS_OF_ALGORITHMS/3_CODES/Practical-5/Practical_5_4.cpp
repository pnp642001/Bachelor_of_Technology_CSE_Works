#include <iostream>
#include <string.h>
using namespace std;
int maximum(int a, int b);
int longestCommonSubsequence(char *X, char *Y, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    if (X[m - 1] == Y[n - 1])
        return 1 + longestCommonSubsequence(X, Y, m - 1, n - 1);
    else
        return maximum(longestCommonSubsequence(X, Y, m, n - 1), longestCommonSubsequence(X, Y, m - 1, n));
}
int maximum(int a, int b)
{
    return (a > b) ? a : b;
}
int main()
{
    char X[100], Y[100];
    cout << "ENTER THE SEQUENCE OF STRING-1 : ";
    cin >> X;
    cout << "ENTER THE SEQUENCE OF STEING-2 : ";
    cin >> Y;
    int m = strlen(X);
    int n = strlen(Y);
    cout << "Length of Longest Common Subsequence is : " << longestCommonSubsequence(X, Y, m, n);

    cout<<"\nPARTH PATEL\n19DCS098"<<endl;
    return 0;
}
