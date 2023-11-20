#include <stdio.h>
#include <stdlib.h>

#define WHITE 0
#define GRAY 1
#define BLACK 2

typedef struct node
{
    int vertex;
    struct node *next;
} node;

typedef struct graph
{
    int numVertices;
    node **adjLists;
    int *color;
} graph;

node *createNode(int v);
graph *createGraph(int vertices);
void addEdge(graph *graph, int src, int dest);
void BFS(graph *graph, int startVertex);

int main()
{
    graph *graph = createGraph(4);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 3);

    BFS(graph, 2);

    return 0;
}

node *createNode(int v)
{
    node *newNode = malloc(sizeof(node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

graph *createGraph(int vertices)
{
    graph *graph = malloc(sizeof(graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(node *));
    graph->color = malloc(vertices * sizeof(int));

    int i;
    for (i = 0; i < vertices; i++)
    {
        graph->adjLists[i] = NULL;
        graph->color[i] = WHITE;
    }

    return graph;
}

void addEdge(graph *graph, int src, int dest)
{
    node *newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

void BFS(graph *graph, int startVertex)
{
    graph->color[startVertex] = GRAY;

    node *queue = createNode(startVertex);
    node *head = queue;

    while (head)
    {
        int currentVertex = head->vertex;
        printf("Visited %d\n", currentVertex);

        node *temp = graph->adjLists[currentVertex];

        while (temp)
        {
            int adjVertex = temp->vertex;

            if (graph->color[adjVertex] == WHITE)
            {
                graph->color[adjVertex] = GRAY;
                node *newNode = createNode(adjVertex);
                queue->next = newNode;
                queue = queue->next;
            }
            temp = temp->next;
        }

        graph->color[currentVertex] = BLACK;
        node *tempNode = head;
        head = head->next;
        free(tempNode);
    }
}
