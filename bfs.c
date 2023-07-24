#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTICES 100
// Structure for a node in the adjacency list
struct Node {
int data;
struct Node* next;
};
// Structure for the adjacency list
struct AdjList {
struct Node* head;
};
// Structure for the graph
struct Graph {
int numVertices;
struct AdjList* array;
};
// Function to create a new node
struct Node* createNode(int data) {
struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
newNode->data = data;
newNode->next = NULL;
return newNode;
}
// Function to create a graph with a given number of vertices
struct Graph* createGraph(int numVertices) {
struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
graph->numVertices = numVertices;
graph->array = (struct AdjList*)malloc(numVertices * sizeof(struct AdjList));
for (int i = 0; i < numVertices; i++) {
graph->array[i].head = NULL;
}
return graph;
}
// Function to add an edge between two vertices
void addEdge(struct Graph* graph, int src, int dest) {
struct Node* newNode = createNode(dest);
newNode->next = graph->array[src].head;
graph->array[src].head = newNode;
}
// Function to perform BFS traversal of the graph
void BFS(struct Graph* graph, int startVertex) {
int visited[MAX_VERTICES] = {0};
// Create a queue for BFS
int queue[MAX_VERTICES];
int front = 0, rear = 0;
// Mark the start vertex as visited and enqueue it
visited[startVertex] = 1;
queue[rear++] = startVertex;
while (front != rear) {
// Dequeue a vertex from the queue
int currentVertex = queue[front++];
printf("%d ", currentVertex);
struct Node* temp = graph->array[currentVertex].head;
while (temp != NULL) {
int adjVertex = temp->data;
if (!visited[adjVertex]) {
visited[adjVertex] = 1;
queue[rear++] = adjVertex;
}
temp = temp->next;
}
}
}
// Main function
int main() {
int numVertices;
printf("Enter the number of vertices in the graph: ");
scanf("%d", &numVertices);
struct Graph* graph = createGraph(numVertices);
int numEdges;
printf("Enter the number of edges: ");
scanf("%d", &numEdges);
printf("Enter the edges (source destination):\n");
for (int i = 0; i < numEdges; i++) {
int src, dest;
scanf("%d %d", &src, &dest);
addEdge(graph, src, dest);
}
int startVertex;
printf("Enter the start vertex for BFS traversal: ");
scanf("%d", &startVertex);
printf("BFS Traversal: ");
BFS(graph, startVertex);
printf("\n");
return 0;
}
