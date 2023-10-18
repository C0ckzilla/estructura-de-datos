/*  Hecho por: Octavio Antonio Juárez Romero
    Matricula: 1577250a
    Materia: Estructura de Datos  */
#ifndef STATICSTACK_H
#define STATICSTACK_H

#define MAX_SIZE 100

struct StaticStack {
    int top;
    int items[MAX_SIZE];
};

struct StaticStack* createStaticStack();
int isStackFull(struct StaticStack* stack);
int isStackEmpty(struct StaticStack* stack);
void push(struct StaticStack* stack, int item);
int pop(struct StaticStack* stack);
void displayStaticStack(struct StaticStack* stack);

#endif // STATICSTACK_H
