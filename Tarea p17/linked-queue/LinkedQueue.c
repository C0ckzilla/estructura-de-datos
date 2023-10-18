/*  Hecho por: Octavio Antonio Juárez Romero
    Matricula: 1577250a
    Materia: Estructura de Datos  */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedQueue.h"

struct LinkedQueue* createLinkedQueue() {
    struct LinkedQueue* queue = (struct LinkedQueue*)malloc(sizeof(struct LinkedQueue));
    queue->front = queue->rear = NULL;
    return queue;
}

void enqueue(struct LinkedQueue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

int dequeue(struct LinkedQueue* queue) {
    if (queue->front == NULL) {
        printf("La cola está vacía.\n");
        return -1;
    }
    int item = queue->front->data;
    struct Node* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return item;
}

void displayLinkedQueue(struct LinkedQueue* queue) {
    if (queue->front == NULL) {
        printf("La cola está vacía.\n");
        return;
    }
    struct Node* temp = queue->front;
    printf("Elementos en la cola: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
