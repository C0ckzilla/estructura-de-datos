/*  Hecho por: Octavio Antonio Juárez Romero
    Matricula: 1577250a
    Materia: Estructura de Datos  */
#include <stdio.h>
#include <stdlib.h>
#include "DynamicStack.h"

struct DynamicStack* createDynamicStack() {
    struct DynamicStack* stack = (struct DynamicStack*)malloc(sizeof(struct DynamicStack));
    stack->top = NULL;
    return stack;
}

void dPush(struct DynamicStack* stack, int item) {
    struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode));
    newNode->data = item;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("%d apilado.\n", item);
}

int dPop(struct DynamicStack* stack) {
    if (stack->top == NULL) {
        printf("La pila está vacía.\n");
        return -1;
    }
    int item = stack->top->data;
    struct DNode* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return item;
}

void displayDynamicStack(struct DynamicStack* stack) {
    if (stack->top == NULL) {
        printf("La pila está vacía.\n");
        return;
    }
    printf("Elementos en la pila: ");
    struct DNode* temp = stack->top;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
