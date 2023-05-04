#include <iostream>
#include <string.h>

using namespace std;
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void permutation(char *a, int l, int r)
{
    int i;
    if (l == r)
        
        cout << a << endl;
    else
    {
        for (i = l; i <= r; i++)
        {
            swap((a + l), (a + i));
            permutation(a, l + 1, r);
            swap((a + l), (a + i)); 
        }
    }
}
int main()

{
    char str[10];

    cout << "ENTER THE STRING : ";
    cin >> str;
    int n = strlen(str);
    permutation(str, 0, n - 1);

    cout<<endl;
    cout << "PARTH PATEL\n19DCS098";
    return 0;
}
