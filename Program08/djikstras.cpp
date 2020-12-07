#include<bits/stdc++.h>
using namespace std;
int mat[30][30],n;
int minimum(int visited[],int dist[])
{
int mindis=9999, mini;
for(int i=0;i<n;i++)
{
if(!visited[i] && dist[i]<mindis)
{
mindis=dist[i];
mini=i;
}
}
return mini;
}

//recursively print  the path
void path(int route[], int i)
{
 
    if (route[i] == - 1)
        return;
 
    path(route, route[i]);
 
    cout<<i<<" ";
}

//djikstras method
void dijkstra(int src,int dest)
{
    //to store distance and check if node is visited
int dist[n],visited[n];
// to store the route
int route[n];
for(int i=0;i<n;i++)
{
dist[i]=9999;
visited[i]=0;
route[0]=-1;
}
dist[src]=0;
for(int i=0;i<n-1;i++)
{
int u=minimum(visited,dist);
visited[u]=1;
for(int v=0;v<n;v++)
{
if(!visited[v] && mat[u][v]!=9999 && dist[u]!=9999 && (dist[u]+mat[u][v])<dist[v])
{
dist[v]=dist[u]+mat[u][v];
route[v]=u;
}
}
}
cout<<"Shortest distance from  "<<src<<" to "<<dest<<" is "<<dist[dest]<<"\n";
    cout<<"Shortest path is ";
   path(route,dest);
cout<<"\n";
}

//main function
int main()
{
    int src,dest;
cout<<"Enter the no. of vertices\n";
cin>>n;
cout<<"Enter the adjacency matrix (9999 for infinity)\n";
for(int i=0;i<n;i++)
{
for(int j=0;j<n;j++)
cin>>mat[i][j];
}

cout<<"Enter the source node\n";
cin>>src;
cout<<"Enter the destination node\n";
cin>>dest;
dijkstra(src,dest);
return 0;
}

	
	
	

