/*  Hecho por: Octavio Antonio Juárez Romero
    Matricula: 1577250a
    Materia: Estructura de Datos  */
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

int isFull(struct Queue* queue) {
    if ((queue->front == queue->rear + 1) || (queue->front == 0 && queue->rear == MAX_SIZE - 1)) return 1;
    return 0;
}

int isEmpty(struct Queue* queue) {
    if (queue->front == -1) return 1;
    return 0;
}

void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("La cola está llena.\n");
        return;
    }
    if (queue->front == -1) queue->front = 0;
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->items[queue->rear] = item;
}

int dequeue(struct Queue* queue) {
    int item;
    if (isEmpty(queue)) {
        printf("La cola está vacía.\n");
        return -1;
    }
    item = queue->items[queue->front];
    if (queue->front == queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    return item;
}

void display(struct Queue* queue) {
    int i;
    if (isEmpty(queue)) {
        printf("La cola está vacía.\n");
        return;
    }
    printf("Elementos en la cola: ");
    if (queue->rear >= queue->front) {
        for (i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->items[i]);
        }
    } else {
        for (i = queue->front; i < MAX_SIZE; i++) {
            printf("%d ", queue->items[i]);
        }
        for (i = 0; i <= queue->rear; i++) {
            printf("%d ", queue->items[i]);
        }
    }
    printf("\n");
}
