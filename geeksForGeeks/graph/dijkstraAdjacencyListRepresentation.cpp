// Driver program to test above functions

 
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct AdjListNode
{
    int dest;
    int weight;
    struct AdjListNode* next;
};
 
// A structure to represent an adjacency liat
struct AdjList
{
    struct AdjListNode *head;  // pointer to head node of list
};
struct Graph{
    int v;
    struct AdjList* array;
};

struct Graph *createGraph(int v)
{
    struct Graph *g = (struct Graph*)malloc(sizeof(struct Graph));
    g->array = (struct AdjList*)malloc(sizeof(struct AdjList)*v);

    for(int i=0;i<v;i++)
        g->array[i]=NULL;
    return g;   
}

void addEdge(struct Graph *graph,int src,int dest,int cost)
{
    if( == NULL)

    struct AdjListNode *temp = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    temp->dest = dest;
    temp->weight = cost;
    temp->next = graph->array[src].head;
    graph->array[src].head = temp;
}

void dijkstra(struct Graph *graph,int src)
{

    int V = graph->V;// Get the number of vertices in graph
    int dist[V]; 

    //initialise minheap

}

int main()
{
    // create the graph given in above fugure
    int V = 9;
    struct Graph* graph = createGraph(V);
    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 7, 8);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 1, 7, 11);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 8, 2);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 3, 5, 14);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 5, 6, 2);
    addEdge(graph, 6, 7, 1);
    addEdge(graph, 6, 8, 6);
    addEdge(graph, 7, 8, 7);
 
    dijkstra(graph, 0);
 
    return 0;
}