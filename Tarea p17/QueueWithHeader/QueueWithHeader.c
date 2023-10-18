/*  Hecho por: Octavio Antonio Juárez Romero
    Matricula: 1577250a
    Materia: Estructura de Datos  */
#include <stdio.h>
#include <stdlib.h>
#include "QueueWithHeader.h"

struct QueueHeader* createQueue() {
    struct QueueHeader* queue = (struct QueueHeader*)malloc(sizeof(struct QueueHeader));
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;
    return queue;
}

int isFull(struct QueueHeader* queue) {
    return queue->size == MAX_SIZE;
}

int isEmpty(struct QueueHeader* queue) {
    return queue->size == 0;
}

void enqueue(struct QueueHeader* queue, int item) {
    if (isFull(queue)) {
        printf("La cola está llena.\n");
        return;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->array[queue->rear] = item;
    queue->size++;
    printf("%d encolado.\n", item);
}

int dequeue(struct QueueHeader* queue) {
    if (isEmpty(queue)) {
        printf("La cola está vacía.\n");
        return -1;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % MAX_SIZE;
    queue->size--;
    return item;
}

void displayQueue(struct QueueHeader* queue) {
    if (isEmpty(queue)) {
        printf("La cola está vacía.\n");
        return;
    }
    printf("Elementos en la cola: ");
    int count, i;
    for (count = 0, i = queue->front; count < queue->size; count++) {
        printf("%d ", queue->array[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}
