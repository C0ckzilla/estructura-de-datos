/*  Hecho por: Octavio Antonio Juárez Romero
    Matricula: 1577250a
    Materia: Estructura de Datos  */
#ifndef DOUBLYLINKEDQUEUE_H
#define DOUBLYLINKEDQUEUE_H

struct DNode {
    int data;
    struct DNode* next;
    struct DNode* prev;
};

struct DoublyLinkedQueue {
    struct DNode* front;
    struct DNode* rear;
};

struct DoublyLinkedQueue* createDoublyLinkedQueue();
void dEnqueue(struct DoublyLinkedQueue* queue, int data);
int dDequeue(struct DoublyLinkedQueue* queue);
void displayDoublyLinkedQueue(struct DoublyLinkedQueue* queue);

#endif // DOUBLYLINKEDQUEUE_H
