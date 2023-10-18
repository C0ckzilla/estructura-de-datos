/*  Hecho por: Octavio Antonio Juárez Romero
    Matricula: 1577250a
    Materia: Estructura de Datos  */
#ifndef CIRCULARQUEUE_H
#define CIRCULARQUEUE_H

struct CNode {
    int data;
    struct CNode* next;
};

struct CircularQueue {
    struct CNode* front;
    struct CNode* rear;
};

struct CircularQueue* createCircularQueue();
void cEnqueue(struct CircularQueue* queue, int data);
int cDequeue(struct CircularQueue* queue);
void displayCircularQueue(struct CircularQueue* queue);

#endif // CIRCULARQUEUE_H
