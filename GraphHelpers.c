#include "GraphHelpers.h"
#include "MUCSGraph.h"

// Get the other vertex of the edge
// Helpful because "to" is not guarateed to be the other vertex
int getOtherVertex(Edge edge, Vertex currentVertex)
{
    if (edge.from == currentVertex.number) {
        return edge.to;
    } else {
        return edge.from;
    }
}

// Get the vertex with the given number
// Helpful because it is 1-indexed
Vertex* getVertex(int vertexNumber, Vertex * V) {
    return &V[vertexNumber - 1];
}