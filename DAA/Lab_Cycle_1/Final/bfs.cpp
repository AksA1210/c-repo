#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void add_edge(vector<int>adj[],int u,int v)
{
    adj[u].push_back(v);
}
void bfs(int source,vector<int>adj[],bool visited[])
{
    queue<int>q;
    q.push(source);
    visited[source] = true;
    while(!q.empty())
    {
        int u = q.front();
        cout<<u<<" ";
        q.pop();
        //Traversal
        for(int i = 0;i<adj[u].size();i++)
        {
            if(!visited[adj[u][i]])
            {
                q.push(adj[u][i]);
                visited[adj[u][i]] = true;
            }
        }
    }
}
int main()
{
    cout<<"--------------BREADTH FIRST SEARCH----------"<<endl;
    int n,e;
    cout<<"Enter the no: of vertices : "<<" ";
    cin>>n;
    vector<int>adj[n];
    bool visited[n];
    for(int i = 0; i<5; i++)
    {
        visited[i] = false;
    }
    cout<<"Enter the no: of edges    : "<<" ";
    cin>>e;
    int a,b,s;
    for(int i = 0 ; i<e;i++)
    {
        cout<<endl;
        cout<<"EDGE "<<i+1<<endl;
        cout<<"Enter the starting point : "<<" ";
        cin>>a;
        cout<<"Enter the final point    : "<<" ";
        cin>>b;
        add_edge(adj,a,b);
    }
    cout<<endl;
    cout<<"Choose any vertex as the source : "<<" ";
    cin>>s;
    cout<<endl;
    cout<<"BFS TRAVERSAL : "<<" ";
    bfs(s,adj,visited);
    cout<<endl;
}