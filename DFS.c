// You might want some more includes here
#include "MUCSGraph.h"
#include "Queue.h"
#include "DFS.h"

#include <stdio.h>
#include <stdlib.h>
#include "GraphHelpers.h"

// Global variable to keep track of ticks
int tick = 0;

void recurseDFS(Vertex * V, int s) {
    // Get adjacency list of the vertex
    Adjacency *adj = getVertex(s, V)->list;

    // Visit all the vertices adjacent to this vertex
    while (adj != NULL) {
        // Get opposite vertex
        int v = getOtherVertex(*(adj->pEdge), *getVertex(s, V));
        Vertex* otherVertex = getVertex(v, V);

        // If the vertex is not visited
        if (otherVertex->color == WHITE) {
            // Mark it visited
            otherVertex->color = GRAY;
            // Increase "time"
            tick++;
            // Increase distance
            otherVertex->d = getVertex(s, V)->d + 1;
            // Recurse to deepen path
            recurseDFS(V, v);
        }
        adj = adj->next;
    }

    // Mark the vertex as finished
    getVertex(s, V)->color = BLACK;
    
    // Increase the "time"
    tick++;
    // Print the vertex and "time" taken
    printf("%d(%d) ", s, tick);
}

// Implement your function here
void PrintDFS(Vertex * V, int countV, Edge * E, int countE)
{
    printf("DFS: \n");
    
    tick = 0; // Reset tick counter to 0
    const int s = 1; // Start at vertex 1

    // Initialize all vertices
    for (int i = 0; i < countV; i++) {
        V[i].color = WHITE;
        V[i].d = -1;
    }

    // Initialize the starting vertex
    getVertex(s, V)->color = GRAY;
    // Increase "time"
    tick++;
    // Initialize distance
    getVertex(s, V)->d = 0;

    // Start the recursive DFS from the starting vertex
    recurseDFS(V, s);

    printf("\n\n");
}