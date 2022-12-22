#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define vr 4
int TSP(int graph[][vr], int p)
{
    vector<int> ver;
    for (int i = 0; i < vr; i++)
    {
        if (i != p)
            ver.push_back(i);
    }
    int m_p = INT_MAX;
    do
    {
        int current_path = 0;
        int k = p;
        for (int i = 0; i < ver.size(); i++)
        {
            current_path += graph[k][ver[i]];
            k = ver[i];
        }
        current_path += graph[k][p];
        m_p = min(m_p, current_path); // to update the value of minimum weight
    } while (next_permutation(ver.begin(), ver.end()));
    return m_p;
}
int main()
{
    cout << "----------------TRAVELLING SALESMAN PROBLEM-------------------------" << endl;

    // int graph[][vr] = {{0, 5, 10, 15}, // values of a graph in a form of matrix
    //                 {5, 0, 20, 30},
    //         {10, 20, 0, 35},
    //      {15, 30, 35, 0}};
    int graph[vr][vr];
    cout << "Enter the adjacency matrix : " << endl;
    for (int i = 0; i < vr; i++)
    {
        for (int j = 0; j < vr; j++)
        {
            cin >> graph[i][j];
        }
        cout << endl;
    }
    int p = 0;
    cout << "\n The result is: " << TSP(graph, p) << endl;
    return 0;
}
