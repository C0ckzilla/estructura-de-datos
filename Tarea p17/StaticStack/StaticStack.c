/*  Hecho por: Octavio Antonio Juárez Romero
    Matricula: 1577250a
    Materia: Estructura de Datos  */
#include <stdio.h>
#include <stdlib.h>
#include "StaticStack.h"

struct StaticStack* createStaticStack() {
    struct StaticStack* stack = (struct StaticStack*)malloc(sizeof(struct StaticStack));
    stack->top = -1;
    return stack;
}

int isStackFull(struct StaticStack* stack) {
    return stack->top == MAX_SIZE - 1;
}

int isStackEmpty(struct StaticStack* stack) {
    return stack->top == -1;
}

void push(struct StaticStack* stack, int item) {
    if (isStackFull(stack)) {
        printf("La pila está llena.\n");
        return;
    }
    stack->items[++stack->top] = item;
    printf("%d apilado.\n", item);
}

int pop(struct StaticStack* stack) {
    if (isStackEmpty(stack)) {
        printf("La pila está vacía.\n");
        return -1;
    }
    return stack->items[stack->top--];
}

void displayStaticStack(struct StaticStack* stack) {
    if (isStackEmpty(stack)) {
        printf("La pila está vacía.\n");
        return;
    }
    printf("Elementos en la pila: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->items[i]);
    }
    printf("\n");
}
