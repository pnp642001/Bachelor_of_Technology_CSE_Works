// C++ program to implement Best First Search using priority
// queue
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
  
vector<vector<pi> > graph;
  
// Function for adding edges to graph
void addedge(int x, int y, int cost)
{
    graph[x].push_back(make_pair(cost, y));
    graph[y].push_back(make_pair(cost, x));
}
  
// Function For Implementing Best First Search
// Gives output path having lowest cost
void best_first_search(int source, int target, int n)
{
    vector<bool> visited(n, false);
    // MIN HEAP priority queue
    priority_queue<pi, vector<pi>, greater<pi> > pq;
    // sorting in pq gets done by first value of pair
    pq.push(make_pair(0, source));
    int s = source;
    visited[s] = true;
    while (!pq.empty()) {
        int x = pq.top().second;
        // Displaying the path having lowest cost
        cout << x << " ";
        pq.pop();
        if (x == target)
            break;
  
        for (int i = 0; i < graph[x].size(); i++) {
            if (!visited[graph[x][i].second]) {
                visited[graph[x][i].second] = true;
                pq.push(make_pair(graph[x][i].first,graph[x][i].second));
            }
        }
    }
}
  
// Driver code to test above methods
int main()
{
    // No. of Nodes
    int v; //NUMBER OF NODES

    cout<<"ENTER THE SIZE OF THE GRAPH: ";
    cin>>v;
    cout<<"----------------------------------"<<endl;
    graph.resize(v);
  
    int start,end,cost;

    for(int i=1;i<=v/2;i++){

        cout<<"ENTER THE STARTING POSITION,ENDING POSITION, AND COST TO REACH : ";
        cin>>start>>end>>cost;
        addedge(start,end,cost);
        cout<<"-------------------------------------------------------------------"<<endl;
    }
    // The nodes shown in above example(by alphabets) are
    // implemented using integers addedge(x,y,cost);
    // addedge(1, 2, 1);
    // addedge(1, 3, 4);
    // addedge(2, 4, 2);
    // addedge(2, 5, 3);
    // addedge(3, 6, 6);
    // addedge(3, 7, 7);
    // addedge(1, 5, 2); //NOT GIVEN IN QUESTION SO ASSUMTION IS TAKEN
    // addedge(5, 4, 5);
  
    int source; //A TAKEN AS SOURCE
    int destination; // D TAKEN AS DESTINATION

    cout<<"ENTER THE SOURCE : ";
    cin>>source;
    cout<<"-------------------"<<endl;
    cout<<"ENTER THE DESTINATION : ";
    cin>>destination;
    cout<<"--------------------------"<<endl;

  
    // Function call
    best_first_search(source, destination, v);
    cout<<endl;
    cout<<"PARTH PATEL\n19DCS098"<<endl;
  
    return 0;
}
