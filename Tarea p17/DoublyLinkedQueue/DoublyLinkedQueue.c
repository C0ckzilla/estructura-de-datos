/*  Hecho por: Octavio Antonio Juárez Romero
    Matricula: 1577250a
    Materia: Estructura de Datos  */
#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedQueue.h"

struct DoublyLinkedQueue* createDoublyLinkedQueue() {
    struct DoublyLinkedQueue* queue = (struct DoublyLinkedQueue*)malloc(sizeof(struct DoublyLinkedQueue));
    queue->front = queue->rear = NULL;
    return queue;
}

void dEnqueue(struct DoublyLinkedQueue* queue, int data) {
    struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = queue->rear;
    if (queue->rear != NULL) {
        queue->rear->next = newNode;
    }
    queue->rear = newNode;
    if (queue->front == NULL) {
        queue->front = newNode;
    }
}

int dDequeue(struct DoublyLinkedQueue* queue) {
    if (queue->front == NULL) {
        printf("La cola está vacía.\n");
        return -1;
    }
    int item = queue->front->data;
    struct DNode* temp = queue->front;
    queue->front = queue->front->next;
    if (queue->front != NULL) {
        queue->front->prev = NULL;
    } else {
        queue->rear = NULL;
    }
    free(temp);
    return item;
}

void displayDoublyLinkedQueue(struct DoublyLinkedQueue* queue) {
    if (queue->front == NULL) {
        printf("La cola está vacía.\n");
        return;
    }
    struct DNode* temp = queue->front;
    printf("Elementos en la cola: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
