/*
Backtracking | Set 6 (Hamiltonian Cycle)
Hamiltonian Path in an undirected graph is a path that visits each vertex exactly once. A Hamiltonian cycle (or Hamiltonian circuit) is a Hamiltonian Path such that there is an edge (in graph) from the last vertex to the first vertex of the Hamiltonian Path. Determine whether a given graph contains Hamiltonian Cycle or not. If it contains, then print the path. Following are the input and output of the required function.

Input:
A 2D array graph[V][V] where V is the number of vertices in graph and graph[V][V] is adjacency matrix representation of the graph. A value graph[i][j] is 1 if there is a direct edge from i to j, otherwise graph[i][j] is 0.

Output:
An array path[V] that should contain the Hamiltonian Path. path[i] should represent the ith vertex in the Hamiltonian Path. The code should also return false if there is no Hamiltonian Cycle in the graph.
*/
// Program to print Hamiltonian cycle
#include<stdio.h>
 #include<stdlib.h>
#include<iostream>
using namespace std;
// Number of vertices in the graph
#define V 5
 
void printSolution(int path[]);
/* A utility function to print solution */
bool isSafe(int v, bool graph[V][V], int path[], int pos)
{
    /* Check if this vertex is an adjacent vertex of the previously
       added vertex. */
    if (graph [ path[pos-1] ][ v ] == false)
        return false;
 
    /* Check if the vertex has already been included.
      This step can be optimized by creating an array of size V */
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;
 
    return true;
}

void printSolution(int path[])
{
    printf ("Solution Exists:"
            " Following is one Hamiltonian Cycle \n");
    for (int i = 0; i < V; i++)
        printf(" %d ", path[i]);
 
    // Let us print the first vertex again to show the complete cycle
    printf(" %d ", path[0]);
    printf("\n");
}
 
bool hamCycleUtil(int *path,bool graph[V][V],int pos)
{
  if(pos == V)
  {
      if(graph[path[pos-1]][path[0]] == true)
        return true;
      else
        return false;
 }
  for(int i=0;i<V;i++)
  { 
      if(isSafe(i,graph,path,pos))
      {
       path[pos] = i;
       if(hamCycleUtil(path,graph,pos+1)==true)
          return true;
        else
          path[pos] = -1;
      }
  }
  
    return false;
}

bool hamCycle(bool graph[V][V])
{
  int *path = (int *)malloc(sizeof(int)*V);

  for(int i=0;i<V;i++)
  {
    path[i]=-1;
  }

  path[0] = 0;
    if ( hamCycleUtil(path, graph, 1) == false )
    {
        printf("\nSolution does not exist");
        return false;
    }
 
    printSolution(path);
    return true;
}

// driver program to test above function
int main()
{
   /* Let us create the following graph
      (0)--(1)--(2)
       |   / \   |
       |  /   \  |
       | /     \ |
      (3)-------(4)    */
   bool graph1[V][V] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 1},
                      {0, 1, 1, 1, 0},
                     };
 
    // Print the solution
    hamCycle(graph1);
 
   /* Let us create the following graph
      (0)--(1)--(2)
       |   / \   |
       |  /   \  |
       | /     \ |
      (3)       (4)    */
    bool graph2[V][V] = {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 0},
                      {0, 1, 1, 0, 0},
                     };
 
    // Print the solution
   // hamCycle(graph2);
 
    return 0;
}