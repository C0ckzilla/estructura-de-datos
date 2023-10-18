/*  Hecho por: Octavio Antonio Juárez Romero
    Matricula: 1577250a
    Materia: Estructura de Datos  */
#include <stdio.h>
#include <stdlib.h>
#include "CircularDoublyLinkedQueue.h"

struct CircularDoublyLinkedQueue* createCircularDoublyLinkedQueue() {
    struct CircularDoublyLinkedQueue* queue = (struct CircularDoublyLinkedQueue*)malloc(sizeof(struct CircularDoublyLinkedQueue));
    queue->front = queue->rear = NULL;
    return queue;
}

void cdEnqueue(struct CircularDoublyLinkedQueue* queue, int data) {
    struct CDNode* newNode = (struct CDNode*)malloc(sizeof(struct CDNode));
    newNode->data = data;
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        newNode->next = newNode->prev = newNode;
    } else {
        newNode->next = queue->front;
        newNode->prev = queue->rear;
        queue->rear->next = newNode;
        queue->front->prev = newNode;
        queue->rear = newNode;
    }
}

int cdDequeue(struct CircularDoublyLinkedQueue* queue) {
    if (queue->front == NULL) {
        printf("La cola está vacía.\n");
        return -1;
    }
    int item = queue->front->data;
    if (queue->front == queue->rear) {
        free(queue->front);
        queue->front = queue->rear = NULL;
    } else {
        struct CDNode* temp = queue->front;
        queue->front = queue->front->next;
        queue->front->prev = queue->rear;
        queue->rear->next = queue->front;
        free(temp);
    }
    return item;
}

void displayCircularDoublyLinkedQueue(struct CircularDoublyLinkedQueue* queue) {
    if (queue->front == NULL) {
        printf("La cola está vacía.\n");
        return;
    }
    struct CDNode* temp = queue->front;
    printf("Elementos en la cola: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != queue->front);
    printf("\n");
}
