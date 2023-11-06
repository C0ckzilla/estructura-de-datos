/*  Hecho por: Octavio Antonio Juárez Romero
    Matricula: 1577250a
    Materia: Estructura de Datos  */

#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

// Función para crear una cola circular
struct CircularQueue* createCircularQueue() {
    struct CircularQueue* queue = (struct CircularQueue*)malloc(sizeof(struct CircularQueue));
    queue->front = queue->rear = NULL; // Inicializa la cola vacía
    return queue;
}

// Función para agregar un elemento al final de la cola
void cEnqueue(struct CircularQueue* queue, int data) {
    struct CNode* newNode = (struct CNode*)malloc(sizeof(struct CNode)); // Crea un nuevo nodo
    newNode->data = data; // Asigna el dato al nodo
    if (queue->rear == NULL) { // Si la cola está vacía
        queue->front = queue->rear = newNode; // El nuevo nodo es el único en la cola
        newNode->next = newNode;  // Hace la cola circular
    } else { // Si la cola no está vacía
        newNode->next = queue->front; // El siguiente del nuevo nodo es el frente de la cola
        queue->rear->next = newNode; // El siguiente del último nodo es el nuevo nodo
        queue->rear = newNode; // El nuevo nodo es ahora el final de la cola
    }
}

// Función para eliminar un elemento del frente de la cola
int cDequeue(struct CircularQueue* queue) {
    if (queue->front == NULL) { // Si la cola está vacía
        printf("La cola está vacía.\n");
        return -1; // Retorna -1 indicando que la cola está vacía
    }
    int item = queue->front->data; // Obtiene el dato del frente de la cola
    if (queue->front == queue->rear) { // Si solo hay un elemento en la cola
        free(queue->front); // Libera el nodo
        queue->front = queue->rear = NULL; // La cola está ahora vacía
    } else { // Si hay más de un elemento en la cola
        struct CNode* temp = queue->front; // Temporal para el frente de la cola
        queue->front = queue->front->next; // El nuevo frente es el siguiente nodo
        queue->rear->next = queue->front; // El siguiente del final de la cola es el nuevo frente
        free(temp); // Libera el nodo que era el frente
    }
    return item; // Retorna el dato eliminado
}

// Función para mostrar los elementos de la cola
void displayCircularQueue(struct CircularQueue* queue) {
    if (queue->front == NULL) { // Si la cola está vacía
        printf("La cola está vacía.\n");
        return; // No hay nada que mostrar
    }
    struct CNode* temp = queue->front; // Temporal para el frente de la cola
    printf("Elementos en la cola: ");
    do {
        printf("%d ", temp->data); // Imprime el dato del nodo
        temp = temp->next; // Avanza al siguiente nodo
    } while (temp != queue->front); // Hasta que el temporal vuelva al frente
    printf("\n");
}
