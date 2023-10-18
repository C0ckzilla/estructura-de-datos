/*  Hecho por: Octavio Antonio Juárez Romero
    Matricula: 1577250a
    Materia: Estructura de Datos  */
#ifndef DYNAMICSTACK_H
#define DYNAMICSTACK_H

struct DNode {
    int data;
    struct DNode* next;
};

struct DynamicStack {
    struct DNode* top;
};

struct DynamicStack* createDynamicStack();
void dPush(struct DynamicStack* stack, int item);
int dPop(struct DynamicStack* stack);
void displayDynamicStack(struct DynamicStack* stack);

#endif // DYNAMICSTACK_H
