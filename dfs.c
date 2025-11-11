#include <stdio.h>
#include <stdlib.h>

struct Node {
    int vertex;
    struct Node* next;
};

struct Graph {
    int numVertices;
    struct Node** adjList;
    int* visited;
};

// Create a new node
struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create a graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;
    graph->adjList = malloc(vertices * sizeof(struct Node*));
    graph->visited = malloc(vertices * sizeof(int));

    for (int i = 0; i < vertices; i++) {
        graph->adjList[i] = NULL;
        graph->visited[i] = 0;
    }
    return graph;
}

// Add edge (undirected)
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// DFS function
void DFS(struct Graph* graph, int vertex) {
    struct Node* temp = graph->adjList[vertex];
    graph->visited[vertex] = 1;
    printf("%d ", vertex);

    while (temp != NULL) {
        int connected = temp->vertex;
        if (graph->visited[connected] == 0)
            DFS(graph, connected);
        temp = temp->next;
    }
}

int main() {
    int v, e, i, src, dest, start;
    printf("Enter number of vertices: ");
    scanf("%d", &v);
    struct Graph* graph = createGraph(v);

    printf("Enter number of edges: ");
    scanf("%d", &e);
    printf("Enter edges (src dest):\n");
    for (i = 0; i < e; i++) {
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS traversal: ");
    DFS(graph, start);

    return 0;
}
