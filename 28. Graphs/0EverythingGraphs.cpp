// DFS Traversal in the graph 

// #include<iostream>

// using namespace std;

// void DFStraversal(int **edges, int n, int sv, bool *visited)
// {
//     cout<<sv<<endl;

//     visited[sv] = true;

//     for(int i=0;i<n;i++)
//     {
//         if(sv == i)
//         {
//             continue;
//         }

//         if(edges[sv][i] == 1)
//         {
//             if(visited[i])
//             {
//                 continue;
//             }
//             DFStraversal(edges,n,i,visited);
//         }
//     }
// }

// int main()
// {
//     int n,e;
//     cin>>n>>e;

//     int **edges = new int *[n];

//     for(int i=0;i<n;i++)
//     {
//         edges[i] = new int[n];

//         for(int j=0;j<n;j++)
//         {
//             edges[i][j] = 0;
//         }
//     }

//     for(int i=0;i<e;i++)
//     {
//         int f,s;
//         cin>>f>>s;

//         edges[f][s] = 1;
//         edges[s][f] = 1;
//     }

//     bool *visited = new bool[n];

//     for(int i=0;i<n;i++)
//     {
//         visited[i] = false;
//     }

//     DFStraversal(edges,n,0,visited);
// }

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

// BFS Traversal in the graph

// #include<iostream>
// #include<queue>

// using namespace std;

// void BFStraversal(int **edges, int n, int sv)
// {
//     queue<int> pendingVertices;

//     bool *visited = new bool[n];

//     for(int i=0;i<n;i++)
//     {
//         visited[i] = false;
//     }

//     pendingVertices.push(sv);
//     visited[sv] = true;


//     while(!pendingVertices.empty())
//     {
//         int currentVertex = pendingVertices.front();
//         pendingVertices.pop();

//         cout<<currentVertex<<endl;

//         for(int i=0;i<n;i++)
//         {
//             if(i == currentVertex)
//             {
//                 continue;
//             }

//             if(edges[currentVertex][i] == 1 && !visited[i])
//             {
//                 pendingVertices.push(i);
//                 visited[i] = true;
//             }
//         }
//     }

//     delete [] visited;
// }

// int main()
// {
//     int n,e;
//     cin>>n>>e;

//     int **edges = new int *[n];

//     for(int i=0;i<n;i++)
//     {
//         edges[i] = new int[n];

//         for(int j=0;j<n;j++)
//         {
//             edges[i][j] = 0;
//         }
//     }

//     for(int i=0;i<e;i++)
//     {
//         int f,s;
//         cin>>f>>s;

//         edges[f][s] = 1;
//         edges[s][f] = 1;
//     }

//     bool *visited = new bool[n];

//     for(int i=0;i<n;i++)
//     {
//         visited[i] = false;
//     }

//     BFStraversal(edges,n,0);
// }

/**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**//**/

// Combined Code for DFS and BFS Traversal

// #include<iostream>
// #include<queue>

// using namespace std;

// int main()
// {
//     int n,e;
//     cin>>n>>e;

//     int **edges = new int*[n];

//     for(int i=0;i<n;i++)
//     {
//         edges[i] = new int[n];

//         for(int j=0;j<n;j++)
//         {
//             edges[i][j] = 0;
//         }
//     }

//     for(int i=0;i<e;i++)
//     {
//         int f,s;
//         cin>>f>>s;

//         edges[f][s] = 1;
//         edges[s][f] = 1;
//     }

//     bool *visited = new bool[n];

//     for(int i=0;i<n;i++)
//     {
//         visited[i] = false;
//     }

//     cout<<"DFS Traversal for the given graph is : "<<endl;
    
//     cout<<"BDS Traversal for the given graph is : "<<endl;
// }

/*
8 9
0 4
0 5
4 3
3 2
2 1
1 3
5 6
3 6
67
*/

