/*  Hecho por: Octavio Antonio Juárez Romero
    Matricula: 1577250a
    Materia: Estructura de Datos  */#ifndef QUEUE_H
#define QUEUE_H

#define MAX_SIZE 10  // Define el tamaño máximo de la cola

struct Queue {
    int items[MAX_SIZE];
    int front, rear;
};

struct Queue* createQueue();
int isFull(struct Queue* queue);
int isEmpty(struct Queue* queue);
void enqueue(struct Queue* queue, int item);
int dequeue(struct Queue* queue);
void display(struct Queue* queue);

#endif // QUEUE_H
