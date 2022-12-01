
#include<bits/stdc++.h>
using namespace std;
class Graph
{
    int V;
    vector<list<int>> adj_list;  
public:
    Graph(int V);
    void add_edge(int v, int w);
    void BFS(int source); 
};
Graph::Graph(int V)
{
    this->V = V;
    adj_list.resize(V);
}
 
void Graph::add_edge(int v, int w)
{
    adj_list[v].push_back(w);
}
 
void Graph::BFS(int source)
{
    vector<bool> visited;
    visited.resize(V,false);
    list<int> queue;
    visited[source] = true;
    queue.push_back(source);
 
    while(!queue.empty())//printing process
    {
        source = queue.front();
        cout << source << " "; //popping the visited one
        queue.pop_front();
        for (auto adjacent: adj_list[source])
        {
            if (!visited[adjacent])
            {
                visited[adjacent] = true;
                queue.push_back(adjacent);
            }
        }
    }
}

int main()
{
    Graph g(5);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(0, 3);
    g.add_edge(1, 2);
    g.add_edge(1, 4);
    cout << "Following is Breadth First Traversal "<< "(starting from vertex 2)"<<"\n";
    g.BFS(0);
 
    return (0);
}
