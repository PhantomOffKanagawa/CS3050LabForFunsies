#ifndef _QUEUE_H
#define _QUEUE_H

#ifdef __cplusplus
extern "C" 
{
#endif

// Data types

typedef struct Node Node;
typedef struct Queue Queue;

// Function prototypes
Queue* createQueue();
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int isEmpty(Queue* q);
void freeQueue(Queue* q);


// Prototypes


#ifdef __cplusplus
}
#endif

#endif