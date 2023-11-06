/*  Hecho por: Octavio Antonio Juárez Romero
    Matricula: 1577250a
    Materia: Estructura de Datos  */

#include <stdio.h>
#include <stdlib.h>
#include "QueueWithHeader.h"

// Función para crear una cola con cabecera
struct QueueHeader* createQueue() {
    struct QueueHeader* queue = (struct QueueHeader*)malloc(sizeof(struct QueueHeader)); // Asignación de memoria para la cola
    queue->front = 0; // Inicialización del frente de la cola a 0
    queue->rear = -1; // Inicialización del final de la cola a -1 (indicando que está vacía)
    queue->size = 0; // Inicialización del tamaño de la cola a 0
    return queue; // Retorno del puntero a la cola creada
}

// Función para verificar si la cola está llena
int isFull(struct QueueHeader* queue) {
    return queue->size == MAX_SIZE; // Devuelve verdadero si el tamaño de la cola es igual al tamaño máximo
}

// Función para verificar si la cola está vacía
int isEmpty(struct QueueHeader* queue) {
    return queue->size == 0; // Devuelve verdadero si el tamaño de la cola es 0
}

// Función para agregar un elemento a la cola
void enqueue(struct QueueHeader* queue, int item) {
    if (isFull(queue)) { // Verifica si la cola está llena antes de encolar
        printf("La cola está llena.\n");
        return; // Si está llena, no hace nada y retorna
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE; // Incrementa el final de la cola de manera circular
    queue->array[queue->rear] = item; // Agrega el elemento al final de la cola
    queue->size++; // Incrementa el tamaño de la cola
    printf("%d encolado.\n", item); // Imprime el elemento encolado
}

// Función para eliminar un elemento de la cola
int dequeue(struct QueueHeader* queue) {
    if (isEmpty(queue)) { // Verifica si la cola está vacía antes de desencolar
        printf("La cola está vacía.\n");
        return -1; // Si está vacía, retorna -1
    }
    int item = queue->array[queue->front]; // Obtiene el elemento del frente de la cola
    queue->front = (queue->front + 1) % MAX_SIZE; // Incrementa el frente de la cola de manera circular
    queue->size--; // Decrementa el tamaño de la cola
    return item; // Retorna el elemento desencolado
}

// Función para mostrar los elementos de la cola
void displayQueue(struct QueueHeader* queue) {
    if (isEmpty(queue)) { // Verifica si la cola está vacía antes de mostrar
        printf("La cola está vacía.\n");
        return; // Si está vacía, no hace nada y retorna
    }
    printf("Elementos en la cola: ");
    int count, i;
    for (count = 0, i = queue->front; count < queue->size; count++) { // Recorre la cola
        printf("%d ", queue->array[i]); // Imprime cada elemento de la cola
        i = (i + 1) % MAX_SIZE; // Incrementa el índice de manera circular
    }
    printf("\n"); // Imprime un salto de línea al final
}
