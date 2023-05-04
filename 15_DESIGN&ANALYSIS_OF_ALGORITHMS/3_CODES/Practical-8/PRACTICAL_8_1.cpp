#include<iostream>
#include <string.h>

using namespace std;

int main()
{
    char t[100], p[100];
    int tn, pn, shift[20] = {0}, s = 0, i, j = 0, count = 0, m = 0;
    cout<<"ENTER THE TEXT : ";
    cin>>t;
   
    cout<<"ENTER THE PATTERN : ";
    cin>>p;

    tn = strlen(t);
    pn = strlen(p);

    while (s != (tn - pn + 1))
    {
        j = 0;
        for (i = s; i < pn + s; i++)
        {
            if (p[j] == t[i])
            {
                count++;
                if (count == pn)
                {
                    count = 0;
                    shift[m] = s;
                    m++;
                }
            }
            else
            {
                count = 0;
                break;
            }
            j++;
        }
        s++;
    }
    if (m > 0)
    {
        printf("\n\nVALID SHIFTS : ");
        for (i = 0; i < m; i++)
            printf("%d \n", shift[i]);
    }
    else
    {
        printf("\n\n NO VALID SHIFTS AVAILABLE");
    }

    cout<<"PARTH PATEL\n19DCS098"<<endl;
    return 0;
}
