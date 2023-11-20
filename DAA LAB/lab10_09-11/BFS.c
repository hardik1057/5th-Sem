#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 100
enum Color
{
    WHITE,
    GRAY,
    BLACK
};
typedef struct
{
    int items[MAX_NODES];
    int front;
    int rear;
} Queue;
void initializeQueue(Queue *queue)
{
    queue->front = -1;
    queue->rear = -1;
}
bool isEmpty(Queue *queue)
{
    return queue->front == -1;
}
void enqueue(Queue *queue, int node)
{
    if (queue->rear == MAX_NODES - 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        if (queue->front == -1)
        {
            queue->front = 0;
        }
        queue->rear++;
        queue->items[queue->rear] = node;
    }
}
int dequeue(Queue *queue)
{
    int node;
    if (isEmpty(queue))
    {
        printf("Queue is empty\n");
        return -1;
    }
    else
    {
        node = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear)
        {
            queue->front = queue->rear = -1;
        }
        return node;
    }
}
void bfsWithColors(int graph[MAX_NODES][MAX_NODES], int nodes, int startNode)
{
    enum Color colors[MAX_NODES];
    for (int i = 0; i < nodes; i++)
    {
        colors[i] = WHITE;
    }
    Queue queue;
    initializeQueue(&queue);
    enqueue(&queue, startNode);
    colors[startNode] = GRAY; 

    while (!isEmpty(&queue))
    {
        int currentNode = dequeue(&queue);
        printf("Processing node: %d\n", currentNode);
        for (int i = 0; i < nodes; i++)
        {
            if (graph[currentNode][i] == 1 && colors[i] == WHITE)
            {
                enqueue(&queue, i);
                colors[i] = GRAY; 
            }
        }
        colors[currentNode] = BLACK;
    }

    printf("BFS completed.\n");
}

int main()
{
    int graph[MAX_NODES][MAX_NODES] = {
        {0, 1, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 1, 1, 0, 0, 0},
        {1, 0, 0, 0, 0, 1, 1, 0},
        {0, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0}};
    int nodes = 8;
    bfsWithColors(graph, nodes, 0);
    return 0;
}
