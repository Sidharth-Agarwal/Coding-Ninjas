#include<iostream>
#include<queue>

using namespace std;

void printBFS(int** edges, int n, int sv)
{
    queue<int> pendinVertices;

    bool * visited = new bool[n];

    for(int i=0;i<n;i++)
    {
        visited[i] = false;
    }

    pendinVertices.push(sv);

    visited[sv] = true;

    while(!pendinVertices.empty())
    {
        int currentVertex = pendinVertices.front();
        pendinVertices.pop();

        cout<<currentVertex<<endl;

        for(int i=0;i<n;i++)
        {
            if(i == currentVertex)
            {
                continue;
            }

            if(edges[currentVertex][i] == 1 && !visited[i])
            {
                pendinVertices.push(i);
                visited[i] = true;
            }
        }
    }

    delete [] visited;
}

int main()
{
    int n;
    int e;

    cin>>n>>e;

    int** edges = new int*[n];

    for(int i=0;i<n;i++)
    {
        edges[i] = new int[n];

        for(int j=0;j<n;j++)
        {
            edges[i][j] = 0;
        }
    }

    for(int i=0;i<e;i++)
    {
        int f,s;

        cin>>f>>s;

        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    printBFS(edges,n,0);

    for(int i=0;i<n;i++)
    {
        delete [] edges;
    }

    delete [] edges;
}


/*

#include <iostream> 
#include <queue> 

using namespace std;

void singleComponentBFS(bool** graph, int v, bool* visited, int vertex) 
{ 
    queue<int> pendingVertices; 
    pendingVertices.push(vertex); 
    visited[vertex] = true; 
    
    while (!pendingVertices.empty()) 
    { 
        int frontVertex = pendingVertices.front(); 
        pendingVertices.pop(); 
        
        cout << frontVertex << " "; 
        
        for (int i = 0; i < v; ++i) 
        { 
            if (graph[frontVertex][i] && !visited[i]) 
            { 
                pendingVertices.push(i); 
                visited[i] = true; 
            } 
        } 
    } 
} 

void BFS(bool** graph, int v) 
{ 
    bool* visited = new bool[v](); 
    
    for (int i = 0; i < v; ++i) 
    { 
        if (!visited[i]) 
        { 
            singleComponentBFS(graph, v, visited, i); 
        } 
    }
    delete[] visited; 
} 

int main() 
{ 
    int v, e; 
    cin >> v >> e; 
    
    bool** graph = new bool*[v]; 
    
    for (int i = 0; i < v; ++i) 
    { 
        graph[i] = new bool[v](); 
    } 
    
    for (int i = 0, a, b; i < e; ++i) 
    { 
        cin >> a >> b; 
        graph[a][b] = true; 
        graph[b][a] = true; 
    } 
    
    BFS(graph, v); 
    
    for (int i = 0; i < v; ++i) 
    { 
        delete[] graph[i]; 
    } 
    delete[] graph; 
}

*/