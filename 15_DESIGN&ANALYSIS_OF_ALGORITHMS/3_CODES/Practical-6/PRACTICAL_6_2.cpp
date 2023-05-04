#include <iostream>
#define INFINITY 10000
#define MAX 10

using namespace std;

void dijikstraAlgorithm(int G[MAX][MAX], int n, int startnode)
{
    int cost[MAX][MAX], distance[MAX], pred[MAX];
    int visited[MAX], count, mindistance, nextnode, i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            if (G[i][j] == 0)
                cost[i][j] = INFINITY;
            else
                cost[i][j] = G[i][j];
    for (i = 0; i < n; i++)
    {
        distance[i] = cost[startnode][i];
        pred[i] = startnode;
        visited[i] = 0;
    }
    distance[startnode] = 0;
    visited[startnode] = 1;
    count = 1;
    while (count < n - 1)
    {
        mindistance = INFINITY;
        for (i = 0; i < n; i++)
            if (distance[i] < mindistance && !visited[i])
            {
                mindistance = distance[i];
                nextnode = i;
            }
        visited[nextnode] = 1;
        for (i = 0; i < n; i++)
            if (!visited[i])
                if (mindistance + cost[nextnode][i] < distance[i])
                {
                    distance[i] = mindistance + cost[nextnode][i];
                    pred[i] = nextnode;
                }
        count++;
    }
    for (i = 0; i < n; i++)
        if (i != startnode)
        {
            
            cout<<"\nDISTANCE OF The NODE "<<i<<" : "<<distance[i];
            
            cout<<"\nPATH : "<<i;
            j = i;
            do
            {
                j = pred[j];
                printf("<-%d", j);
            } while (j != startnode);
        }
}

int main()
{
    int G[MAX][MAX], i, j, n, u;
    
    cout<<"ENTER THE NUMBER OF VERTICES : ";
    cin>>n;
   

    cout<<"\nENTER THE ADJACENCY MATRIX : "<<endl;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cin>>G[i][j];
    
    cout<<"\nENTER THE STARTING NODE : ";
    cin>>u;
    dijikstraAlgorithm(G, n, u);

    cout<<"\nPARTH PATEL\n19DCS098";

    return 0;
}
