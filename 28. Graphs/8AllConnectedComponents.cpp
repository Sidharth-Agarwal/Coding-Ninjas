/*

Code : All connected components
Send Feedback
Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. You need to take input in main and create a function which should return all the connected components. And then 
print them in the main, not inside function.
Print different components in new line. And each component should be printed in increasing order (separated by space). 
Order of different components doesn't matter.
Input Format :
The first line of input contains two integers, that denote the value of V and E.
Each of the following E lines contains two space separated integers, that denote that there exists an edge between 
vertex a and b.
Output Format :
Print different components in new line. And each component should be printed in increasing order of vertices 
(separated by space). Order of different components doesn't matter.
Constraints :
0 <= V <= 1000
0 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Sample Input 1:
4 2
0 1
2 3
Sample Output 1:
0 1 
2 3 
Sample Input 2:
4 3
0 1
1 3
0 3
Sample Output 2:
0 1 3 
2

*/

#include <algorithm>
#include <iostream> 
#include <queue> 
#include <vector> 

using namespace std; 

vector<int> getOneComponent(bool** graph, int startingVertex, int v, bool* visited) 
{ 
    vector<int> component; 
    
    queue<int> pendingNodes; 
    
    pendingNodes.push(startingVertex); 
    visited[startingVertex] = true; 
    
    while (!pendingNodes.empty()) 
    { 
        int current = pendingNodes.front(); 
        pendingNodes.pop(); 
        
        component.push_back(current); 
        
        for (int i = 0; i < v; ++i) 
        { 
            if (graph[current][i] && !visited[i]) 
            { 
                pendingNodes.push(i); 
                visited[i] = true; 
            } 
        } 
    } 
    
    return component; 
} 

vector<vector<int>> getAllComponents(bool** graph, int v) 
{ 
    vector<vector<int>> result; 
    
    bool* visited = new bool[v](); 
    
    for (int i = 0; i < v; ++i) 
    { 
        if (!visited[i]) 
        { 
            vector<int> component = getOneComponent(graph, i, v, visited); 
            
            result.push_back(component); 
        } 
    } 
    
    delete[] visited; 
    
    return result; 
} 

int main() 
{ 
    int v, e; 
    cin >> v >> e; 
    
    bool** graph = new bool*[v]; 
    
    for (int i = 0; i < v; i++) 
    { 
        graph[i] = new bool[v](); 
    } 
    
    for (int i = 0, a, b; i < e; ++i) 
    { 
        cin >> a >> b; 
        graph[a][b] = true; 
        graph[b][a] = true; 
    } 
    
    vector<vector<int>> connectedComponenents = getAllComponents(graph, v); 
    
    for (int i = 0; i < connectedComponenents.size(); i++) 
    { 
        sort(connectedComponenents[i].begin(), connectedComponenents[i].end()); 
        
        for (int j = 0; j < connectedComponenents[i].size(); j++) 
        { 
            cout << connectedComponenents[i][j] << " "; 
        } 
        cout << "\n"; 
    } 
}