#include<stdio.h>
#include <string.h>
int queue[100], front = -1, rear = -1;
int stack[100], top = -1;
void enqueue(int d) {
    queue[++rear] = d;
    if (front == -1) front++;
}
void push(int d) {
    stack[++top] = d;
}
int dequeue() {
    int d = queue[front++];
    if (front > rear) front = rear = -1;
    return d;
}
int pop() {
    return stack[top--];
}
int isQueueEmpty() {
    if (front == -1 && rear == -1) return 1;
    return 0;
}
int isStackEmpty() {
    if (top == -1) return 1;
    return 0;
}
void addEdge(int vertices, int Graph[vertices][vertices], int u, int v) {
    Graph[u][v] = 1;
    Graph[v][u] = 1;
}
void BFS(int vertices, int Graph[vertices][vertices]) {
    int vertex, visited[vertices], added[vertices], i;
    memset(visited, 0, vertices * sizeof(int));
    memset(added, 0, vertices * sizeof(int));
    printf("Enter start vertex:");
    scanf("%d", & vertex);
    printf("BFS Traversal Result:");
    enqueue(vertex);
    visited[vertex] = 1;
    added[vertex] = 1;
    while (!isQueueEmpty()) {
        for (i = 0; i < vertices; i++) {
            if (visited[i] != 1 && added[i] != 1 && Graph[vertex][i] != 0) {
                enqueue(i);
                added[i] = 1;
            }
        }
        vertex = dequeue();
        visited[vertex] = 1;
        printf("%d ", vertex);
    }
    printf("\n");
}
void DFS(int vertices, int Graph[vertices][vertices]) {
    int vertex, visited[vertices], added[vertices], i;
    memset(visited, 0, vertices * sizeof(int));
    memset(added, 0, vertices * sizeof(int));
    printf("Enter start vertex:");
    scanf("%d", & vertex);
    printf("BFS Traversal Result:");
    push(vertex);
    visited[vertex] = 1;
    added[vertex] = 1;
    while (!isStackEmpty()) {
        for (i = 0; i < vertices; i++) {
            if (visited[i] != 1 && added[i] != 1 && Graph[vertex][i] != 0) {
                push(i);
                added[i] = 1;
            }
        }
        vertex = pop();
        visited[vertex] = 1;
        printf("%d ", vertex);
    }
    printf("\n");
}
int main() {
    int vertices, ch, u, v;
    printf("Enter the number of vertices in the Graph:");
    scanf("%d", & vertices);
    int Graph[vertices][vertices];
    memset(Graph, 0, vertices * vertices * sizeof(int));
    do {
        printf("Select any one:\n1. Add an Edge\n2. Traverse using BFS\n3. Traverse using DFS\n4. Exit\n");
        printf("Enter your selection:");
        scanf("%d", & ch);
        switch (ch) {
        case 1:
            printf("Enter vertices along which edge will be added(starts at 0)(u,v):");
            scanf("%d %d", & u, & v);
            addEdge(vertices, Graph, u, v);
            break;
        case 2:
            BFS(vertices, Graph);
            break;
        case 3:
            DFS(vertices, Graph);
            break;
        }
    } while (ch != 4);
}
