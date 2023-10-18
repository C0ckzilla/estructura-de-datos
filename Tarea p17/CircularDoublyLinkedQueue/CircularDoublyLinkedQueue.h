/*  Hecho por: Octavio Antonio Juárez Romero
    Matricula: 1577250a
    Materia: Estructura de Datos  */
#ifndef CIRCULARDOUBLYLINKEDQUEUE_H
#define CIRCULARDOUBLYLINKEDQUEUE_H

struct CDNode {
    int data;
    struct CDNode* next;
    struct CDNode* prev;
};

struct CircularDoublyLinkedQueue {
    struct CDNode* front;
    struct CDNode* rear;
};

struct CircularDoublyLinkedQueue* createCircularDoublyLinkedQueue();
void cdEnqueue(struct CircularDoublyLinkedQueue* queue, int data);
int cdDequeue(struct CircularDoublyLinkedQueue* queue);
void displayCircularDoublyLinkedQueue(struct CircularDoublyLinkedQueue* queue);

#endif // CIRCULARDOUBLYLINKEDQUEUE_H
