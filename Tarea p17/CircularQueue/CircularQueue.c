/*  Hecho por: Octavio Antonio Juárez Romero
    Matricula: 1577250a
    Materia: Estructura de Datos  */
#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

struct CircularQueue* createCircularQueue() {
    struct CircularQueue* queue = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    queue->front = queue->rear = NULL;
    return queue;
}

void cEnqueue(struct CircularQueue* queue, int data) {
    struct CNode* newNode = (struct CNode*)malloc(sizeof(struct CNode));
    newNode->data = data;
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        newNode->next = newNode;  // Hace la cola circular
    } else {
        newNode->next = queue->front;
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int cDequeue(struct CircularQueue* queue) {
    if (queue->front == NULL) {
        printf("La cola está vacía.\n");
        return -1;
    }
    int item = queue->front->data;
    if (queue->front == queue->rear) {
        free(queue->front);
        queue->front = queue->rear = NULL;
    } else {
        struct CNode* temp = queue->front;
        queue->front = queue->front->next;
        queue->rear->next = queue->front;
        free(temp);
    }
    return item;
}

void displayCircularQueue(struct CircularQueue* queue) {
    if (queue->front == NULL) {
        printf("La cola está vacía.\n");
        return;
    }
    struct CNode* temp = queue->front;
    printf("Elementos en la cola: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != queue->front);
    printf("\n");
}
