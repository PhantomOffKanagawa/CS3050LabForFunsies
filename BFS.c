// You might want some more includes here
#include "MUCSGraph.h"
#include "Queue.h"
#include "BFS.h"

#include <stdio.h>
#include <stdlib.h>
#include "GraphHelpers.h"

// Implement your function here
void PrintBFS(Vertex * V, int countV, Edge * E, int countE, int s)
{
    printf("BFS: \n");

    // Create queue
    Queue *q = createQueue();

    // Initialize all vertices
    for (int i = 0; i < countV; i++) {
        V[i].color = WHITE;
        V[i].d = -1;
    }

    // Enqueue the starting vertex and initialize color and distance
    enqueue(q, s);
    V[s].color = GRAY;
    V[s].d = 0;

    while (!isEmpty(q)) {
        // Dequeue a vertex from queue and print it
        int u = dequeue(q);

        // Get the adjacency list of the dequeued vertex
        Adjacency *adj = getVertex(u, V)->list;
        // Visit all the vertices adjacent to this vertex
        while (adj != NULL) {
            // Get opposite vertex
            int v = getOtherVertex(*(adj->pEdge), *getVertex(u, V));
            //* int v = adj->pEdge->to;

            // If the vertex is not visited
            if (V[v].color == WHITE) {
                // Mark it visited
                V[v].color = GRAY;
                // Increase distance
                V[v].d = V[u].d + 1;
                // Enqueue it
                enqueue(q, v);
            }
            adj = adj->next;
        }

        // Mark the vertex as finished
        V[u].color = BLACK;
        // Print the vertex and distance
        printf("%d(%d) ", u, V[u].d);
    }

    // Free the queue
    freeQueue(q);

    printf("\n\n");
}
