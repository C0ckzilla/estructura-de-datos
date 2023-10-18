/*  Hecho por: Octavio Antonio Juárez Romero
    Matricula: 1577250a
    Materia: Estructura de Datos  */
#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

struct Node {
    int data;
    struct Node* next;
};

struct LinkedQueue {
    struct Node* front;
    struct Node* rear;
};

struct LinkedQueue* createLinkedQueue();
void enqueue(struct LinkedQueue* queue, int data);
int dequeue(struct LinkedQueue* queue);
void displayLinkedQueue(struct LinkedQueue* queue);

#endif // LINKEDQUEUE_H
