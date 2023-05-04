#include <iostream>
using namespace std;
int max(int x, int y)
{
    if (x > y)
        return x;
    else
        return y;
}
int knapsackSolution(int bagCapacity, int weight[], int profit[], int number)
{
    int matrix[number + 1][bagCapacity + 1];
    for (int i = 0; i < number + 1; i++)
        for (int j = 0; j < bagCapacity + 1; j++)
        {
            if (i == 0 || j == 0)
                matrix[i][j] = 0;
            else if (j >= weight[i - 1])
                matrix[i][j] = max(matrix[i - 1][j], profit[i - 1] + matrix[i - 1][j - weight[i - 1]]);
            else
                matrix[i][j] = matrix[i - 1][j];
        }
    return matrix[number][bagCapacity];
}
int main()
{
    int number, bagCapacity;
    cout << "\nENTER THE SIZE OF ARRAY : ";
    cin >> number;

    int weight[number], profit[number];
    cout << "\nENTER THE WEIGHTS :";
    for (int i = 0; i < number; i++)
        cin >> weight[i];
    cout << "ENTER THE PROFITS :";
    for (int i = 0; i < number; i++)
        cin >> profit[i];
    cout << "ENTER THE CAPACITY OF BAG : ";
    cin >> bagCapacity;
    cout << "\nMAXIMUM POOSIBLE PROFIT: " << knapsackSolution(bagCapacity, weight, profit, number) << endl;
    cout << "PARTH PATEL\n19DCS098" << endl;
    return 0;
}