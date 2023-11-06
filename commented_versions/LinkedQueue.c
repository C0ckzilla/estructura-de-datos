/*  Hecho por: Octavio Antonio Juárez Romero
    Matricula: 1577250a
    Materia: Estructura de Datos  */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedQueue.h"

// Función para crear una cola enlazada
struct LinkedQueue* createLinkedQueue() {
    struct LinkedQueue* queue = (struct LinkedQueue*)malloc(sizeof(struct LinkedQueue));
    queue->front = queue->rear = NULL; // Inicializa la cola vacía
    return queue;
}

// Función para agregar un elemento al final de la cola
void enqueue(struct LinkedQueue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Crea un nuevo nodo
    newNode->data = data; // Asigna el dato al nodo
    newNode->next = NULL; // El siguiente del nuevo nodo es NULL
    if (queue->rear == NULL) { // Si la cola está vacía
        queue->front = queue->rear = newNode; // El nuevo nodo es el frente y el final de la cola
        return;
    }
    queue->rear->next = newNode; // El siguiente del último nodo es el nuevo nodo
    queue->rear = newNode; // El nuevo nodo es ahora el último nodo
}

// Función para eliminar un elemento del frente de la cola
int dequeue(struct LinkedQueue* queue) {
    if (queue->front == NULL) { // Si la cola está vacía
        printf("La cola está vacía.\n");
        return -1; // Retorna -1 indicando que la cola está vacía
    }
    int item = queue->front->data; // Obtiene el dato del frente de la cola
    struct Node* temp = queue->front; // Temporal para el frente de la cola
    queue->front = queue->front->next; // El nuevo frente es el siguiente nodo
    if (queue->front == NULL) { // Si la cola se vació
        queue->rear = NULL; // El último nodo también es NULL
    }
    free(temp); // Libera el nodo que era el frente
    return item; // Retorna el dato eliminado
}

// Función para mostrar los elementos de la cola
void displayLinkedQueue(struct LinkedQueue* queue) {
    if (queue->front == NULL) { // Si la cola está vacía
        printf("La cola está vacía.\n");
        return; // No hay nada que mostrar
    }
    struct Node* temp = queue->front; // Temporal para el frente de la cola
    printf("Elementos en la cola: ");
    while (temp != NULL) { // Mientras haya nodos en la cola
        printf("%d ", temp->data); // Imprime el dato del nodo
        temp = temp->next; // Avanza al siguiente nodo
    }
    printf("\n");
}
