#include <iostream>
#include <bits/stdc++.h>
using namespace std;
const int MAX = 99999; // INF
#define V 5
bool createsMST(int u, int v, vector<bool> V_MST)
{
    if (u == v)
    {
        return false;
    }
    if (V_MST[u] == false && V_MST[v] == false)
    {
        return false;
    }
    else if (V_MST[u] == true && V_MST[v] == true)
    {
        return false;
    }
    return true;
}
void MST_display(int cost[][V])
{
    vector<bool> V_MST(V, false);
    V_MST[0] = true;
    int edgeNo = 0, MSTcost = 0;
    while (edgeNo < V - 1)
    {
        int min = MAX, a = -1, b = -1;
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (cost[i][j] < min)
                {
                    if (createsMST(i, j, V_MST))
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }
        if (a != -1 && b != -1)
        {
            cout << "Edge " << edgeNo++ << " : (" << a << " , " << b << " ) : cost = " << min << endl;
            MSTcost += min;
            V_MST[b] = V_MST[a] = true;
        }
    }
    cout << "Cost of MST = " << MSTcost;
}
int main()
{
    int G[V][V];
    int source;
    for (int i = 0; i < V; i++)
    {
        cout << "Enter the distance from vertex " << i << " to each vertex : "
             << " ";
        for (int j = 0; j < V; j++)
        {
            cin >> G[i][j];
        }
    }

    for (int i = 0; i < V; i++) // Assigning the values (initialisation)
    {
        for (int j = 0; j < V; j++)
        {
            if (G[i][j] == -1)
            {
                G[i][j] = MAX;
            }
            else
            {
                G[i][j] = G[i][j];
            }
        }
    }
    cout << endl<< endl;
    cout << "Choose any vertex as source : "<< " ";
    cin >> source;
    cout << endl;
    cout << "The MST for the given tree is :\n";
    MST_display(G);
    return 0;
}


Output :

Enter the distance from vertex 0 to each vertex :  0 3 -1 -1 -1
Enter the distance from vertex 1 to each vertex :  3 0 10 2 6
Enter the distance from vertex 2 to each vertex :  -1 10 0 4 -1
Enter the distance from vertex 3 to each vertex :  -1 2 4 0 1
Enter the distance from vertex 4 to each vertex :  -1 6 -1 1 0


Choose any vertex as source :  2

The MST for the given tree is :
Edge 0 : (0 , 1 ) : cost = 3
Edge 1 : (1 , 3 ) : cost = 2
Edge 2 : (3 , 4 ) : cost = 1
Edge 3 : (2 , 3 ) : cost = 4
Cost of MST = 10
