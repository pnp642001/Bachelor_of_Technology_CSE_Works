#include <bits/stdc++.h>
using namespace std;
int MatrixChainMultiplication(int product[], int n)
{
    int matrix[n][n];
    int i, j, k, L, q;
    for (i = 1; i < n; i++)
        matrix[i][i] = 0;

    for (L = 2; L < n; L++)
    {
        for (i = 1; i < n - L + 1; i++)
        {
            j = i + L - 1;
            matrix[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++)
            {

                q = matrix[i][k] + matrix[k + 1][j] +
                    product[i - 1] * product[k] * product[j];
                if (q < matrix[i][j])
                    matrix[i][j] = q;
            }
        }
    }
    return matrix[1][n - 1];
}
int main()
{
    int n;

    cout<<"-------------------------------------------"<<endl;
    cout << "ENTER THE TOTAL NUMBER OF MATRICES : ";
    cin >> n;
    int arr[n];
    cout<<"-------------------------------------------"<<endl;
    for (int i = 0; i < n; i++)
    {
        cout << "ENTER THE NxN DIMENSIONS OF MATRIX -> " << i << " : ";
        
        cin >> arr[i];
        cout<<"-------------------------------------------"<<endl;
    }
    int length = sizeof(arr) / sizeof(arr[0]);
    cout<<"-------------------------------------------"<<endl;
    cout << "MINIMUM NUMBER OF MULTIPLICATIONS NEEDED : " << MatrixChainMultiplication(arr, length) << endl;
    cout<<"-------------------------------------------"<<endl;
    cout << "PARTH PATEL\n19DCS098" << endl;
    cout<<"-------------------------------------------"<<endl;
    cout<<"[CS 351] DAA EXTERNAL PRACTICAL EXAM"<<endl;
    cout<<"-------------------------------------------"<<endl;
    return 0;
}