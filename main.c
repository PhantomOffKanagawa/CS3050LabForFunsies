// Do not change this file, except while you are debugging.
// The TAs will use the original main for grading.  You might
// want to pull down the original starter code and just copy in your
// BFS.c, DFS.c, Queue.c and Queue.h files and build it.  This would
// assure that you haven't broken anything by changing other files.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MUCSGraph.h"
#include "BFS.h"
#include "DFS.h"

int main(void)
{
    /******************************************************/
    /* Set things up by loading the graph and printing it */
    int countVertices, countEdges;

	int isDirected = GetDirected();
    int startNode = GetStartNode();
    GetCounts(&countVertices,&countEdges);

    Vertex vertices[countVertices];
    Edge edges[countEdges];
    memset(vertices,0,sizeof(vertices));
    memset(edges,0,sizeof(edges));

    GetEdges(edges,countEdges);
    BuildAdjacency(vertices,edges,countVertices,countEdges);
    printf("\n\n****Graph:\n");
    if (isDirected)
    {
        printf("DIRECTED\n");
    }
    else
    {
        printf("UNDIRECTED\n");
    }
    printf("Start node: %d\n",startNode);
    PrintVertices(vertices,countVertices);
    printf("\n");
    /******************************************************/

    PrintBFS(vertices,countVertices,edges,countEdges,startNode);
    PrintDFS(vertices,countVertices,edges,countEdges);
}
