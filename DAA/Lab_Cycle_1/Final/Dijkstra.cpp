#include<iostream>
#include<stdio.h>
using namespace std;
#define INF 9999
#define V 5

void dijkstra(int G[V][V],int num,int start) 
{
    int cost[V][V];
    int distance[V],pred[V];
    int visited[V],count,min_dist,next,i,j;
    for(i=0;i<num;i++)            //Assigning the values (initialisation)
    {
        for(j=0;j<num;j++)
        {
            if(G[i][j]==0)
            {
                cost[i][j]=INF;
            }
            else
            {
                cost[i][j]=G[i][j];
            }
        } 
    }     
    for(i=0;i<num;i++) 
    {
        distance[i]=cost[start][i];
        pred[i]=start;   
        visited[i] = 0; 
    }
    distance[start] = 0;
    visited[start] = 1;
    count = 1;
    while(count < num-1) 
    {
        min_dist=INF;
        for(i=0;i<num;i++)
        {
            if(distance[i]<min_dist && !visited[i])    //Initial checking for shortest path
            {
                min_dist=distance[i];
                next = i;
            }
        }    
        visited[next] = 1;
        for(i=0;i<num;i++)
        {
            if(!visited[i])
            {
                if(min_dist+cost[next][i]<distance[i])        //Relax function
                {
                    distance[i]=min_dist+cost[next][i];
                    pred[i]=next;
                }
            }
        }        
        count++;
    }
    cout<<endl;
    cout<<"Vertex"<<"       "<<"Distance"<<endl<<endl;
    for(i=0;i<num;i++)
    {
        //if(i!=start) 
        {
            cout<<i<<"              "<<distance[i]<<endl;
            cout<<endl;
        } 
    }
}   
int main() 
{
    int G[V][V];
    int source;
    for(int i = 0; i <  V; i++)
    {
        cout<<"Enter the distance from vertex "<< i <<" to each vertex : "<<" ";
        for(int j = 0;j < V; j++)
        {
            cin>>G[i][j];
        }
    }
    cout<<endl<<endl;
    cout<<"Choose any vertex as source : "<<" ";
    cin>>source;
    dijkstra(G,V,source);
    return 0;
}
