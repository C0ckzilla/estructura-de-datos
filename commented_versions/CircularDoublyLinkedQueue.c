/*  Hecho por: Octavio Antonio Juárez Romero
    Matricula: 1577250a
    Materia: Estructura de Datos  */

#include <stdio.h>
#include <stdlib.h>
#include "CircularDoublyLinkedQueue.h"

// Esta función crea una cola doblemente enlazada circular vacía.
struct CircularDoublyLinkedQueue* createCircularDoublyLinkedQueue() {
    // Se asigna memoria para la estructura de la cola.
    struct CircularDoublyLinkedQueue* queue = (struct CircularDoublyLinkedQueue*)malloc(sizeof(struct CircularDoublyLinkedQueue));
    // Se inicializan los punteros front y rear a NULL, indicando que la cola está vacía.
    queue->front = queue->rear = NULL;
    // Se retorna el puntero a la cola creada.
    return queue;
}

// Esta función añade un elemento al final de la cola.
void cdEnqueue(struct CircularDoublyLinkedQueue* queue, int data) {
    // Se asigna memoria para el nuevo nodo.
    struct CDNode* newNode = (struct CDNode*)malloc(sizeof(struct CDNode));
    // Se establece el dato del nuevo nodo.
    newNode->data = data;
    // Si la cola está vacía, el nuevo nodo será el único elemento y se apuntará a sí mismo.
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        newNode->next = newNode->prev = newNode;
    } else {
        // Si la cola no está vacía, se inserta el nuevo nodo al final y se actualizan los enlaces.
        newNode->next = queue->front;
        newNode->prev = queue->rear;
        queue->rear->next = newNode;
        queue->front->prev = newNode;
        queue->rear = newNode;
    }
}

// Esta función elimina y retorna el elemento al frente de la cola.
int cdDequeue(struct CircularDoublyLinkedQueue* queue) {
    // Si la cola está vacía, se retorna -1.
    if (queue->front == NULL) {
        printf("La cola está vacía.\n");
        return -1;
    }
    // Se obtiene el dato del nodo al frente.
    int item = queue->front->data;
    // Si hay un solo elemento, se elimina y se actualizan los punteros a NULL.
    if (queue->front == queue->rear) {
        free(queue->front);
        queue->front = queue->rear = NULL;
    } else {
        // Si hay más de un elemento, se elimina el nodo al frente y se actualizan los enlaces.
        struct CDNode* temp = queue->front;
        queue->front = queue->front->next;
        queue->front->prev = queue->rear;
        queue->rear->next = queue->front;
        free(temp);
    }
    // Se retorna el dato del nodo eliminado.
    return item;
}

// Esta función muestra todos los elementos de la cola.
void displayCircularDoublyLinkedQueue(struct CircularDoublyLinkedQueue* queue) {
    // Si la cola está vacía, se muestra un mensaje y se termina la función.
    if (queue->front == NULL) {
        printf("La cola está vacía.\n");
        return;
    }
    // Se recorren los nodos de la cola y se muestran sus datos.
    struct CDNode* temp = queue->front;
    printf("Elementos en la cola: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != queue->front); // Se continúa hasta volver al nodo inicial.
    printf("\n");
}
