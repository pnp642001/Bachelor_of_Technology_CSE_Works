#include <iostream>
#include <string.h>
#define d 256
using namespace std;
void search(char pattern[], char text[], int q)
{
    int M = strlen(pattern);
    int N = strlen(text);
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;
    for (i = 0; i < M; i++)
    {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }
    for (i = 0; i <= N - M; i++)
    {
        if (p == t)

        {
            for (j = 0; j < M; j++)
            {
                if (text[i + j] != pattern[j])
                    break;
            }
            if (j == M)
              
                cout<<"PATTERN FOUND AT INDEX : "<<i<<endl;
        }
        if (i < N - M)
        {
            t = (d * (t - text[i] * h) + text[i + M]) % q;
            if (t < 0)
                t = (t + q);
        }
    }
}
int main()
{
    

    char text[100];
    char patterntern[100];
    int q;

    cout<<"ENTER THE TEXT : ";
    cin>>text;
    cout<<"ENTER THE PATTERN : ";
    cin>>patterntern;

    cout<<"ENTER THE VALUE OF q : ";
    cin>>q;
    search(patterntern, text, q);

    cout<<"PARTH PATEL\n19DCS098"<<endl;
    return 0;
}
