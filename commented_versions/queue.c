/*  Hecho por: Octavio Antonio Juárez Romero
    Matricula: 1577250a
    Materia: Estructura de Datos  */

#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

// Función para crear una nueva cola estática circular
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Función para verificar si la cola está llena
int isFull(struct Queue* queue) {
    // Si el frente está justo después del final, o si el frente está al inicio y el final al máximo menos uno, está llena
    if ((queue->front == queue->rear + 1) || (queue->front == 0 && queue->rear == MAX_SIZE - 1)) return 1;
    return 0;
}

// Función para verificar si la cola está vacía
int isEmpty(struct Queue* queue) {
    // Si el frente es -1, la cola está vacía
    if (queue->front == -1) return 1;
    return 0;
}

// Función para agregar un elemento al final de la cola
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("La cola está llena.\n");
        return;
    }
    if (queue->front == -1) queue->front = 0; // Si la cola estaba vacía, establece el frente en 0
    queue->rear = (queue->rear + 1) % MAX_SIZE; // Incrementa el final de manera circular
    queue->items[queue->rear] = item; // Agrega el elemento al final
}

// Función para eliminar un elemento del frente de la cola
int dequeue(struct Queue* queue) {
    int item;
    if (isEmpty(queue)) {
        printf("La cola está vacía.\n");
        return -1; // Retorna -1 si la cola está vacía
    }
    item = queue->items[queue->front]; // Obtiene el elemento del frente
    if (queue->front == queue->rear) {
        // Si solo hay un elemento, restablece la cola a su estado vacío
        queue->front = -1;
        queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE; // Incrementa el frente de manera circular
    }
    return item; // Retorna el elemento eliminado
}

// Función para mostrar los elementos de la cola
void display(struct Queue* queue) {
    int i;
    if (isEmpty(queue)) {
        printf("La cola está vacía.\n");
        return; // No hay nada que mostrar si la cola está vacía
    }
    printf("Elementos en la cola: ");
    if (queue->rear >= queue->front) {
        // Si el final no ha dado la vuelta al principio
        for (i = queue->front; i <= queue->rear; i++) {
            printf("%d ", queue->items[i]); // Muestra los elementos desde el frente hasta el final
        }
    } else {
        // Si el final ha dado la vuelta al principio
        for (i = queue->front; i < MAX_SIZE; i++) {
            printf("%d ", queue->items[i]); // Muestra los elementos desde el frente hasta el final del arreglo
        }
        for (i = 0; i <= queue->rear; i++) {
            printf("%d ", queue->items[i]); // Continúa mostrando desde el inicio del arreglo hasta el final
        }
    }
    printf("\n");
}
