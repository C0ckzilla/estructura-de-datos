/*  Hecho por: Octavio Antonio Juárez Romero
    Matricula: 1577250a
    Materia: Estructura de Datos  */
#ifndef QUEUEWITHHEADER_H
#define QUEUEWITHHEADER_H

#define MAX_SIZE 100

struct QueueHeader {
    int front;
    int rear;
    int size;
    int array[MAX_SIZE];
};

struct QueueHeader* createQueue();
int isFull(struct QueueHeader* queue);
int isEmpty(struct QueueHeader* queue);
void enqueue(struct QueueHeader* queue, int item);
int dequeue(struct QueueHeader* queue);
void displayQueue(struct QueueHeader* queue);

#endif // QUEUEWITHHEADER_H
