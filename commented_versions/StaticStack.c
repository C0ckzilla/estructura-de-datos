/*  Hecho por: Octavio Antonio Juárez Romero
    Matricula: 1577250a
    Materia: Estructura de Datos  */

#include <stdio.h>
#include <stdlib.h>
#include "StaticStack.h"

// Función para crear una pila estática
struct StaticStack* createStaticStack() {
    struct StaticStack* stack = (struct StaticStack*)malloc(sizeof(struct StaticStack)); // Asigna memoria para la pila
    stack->top = -1; // Inicializa el índice del tope de la pila a -1 (pila vacía)
    return stack; // Retorna el puntero a la pila
}

// Función para verificar si la pila está llena
int isStackFull(struct StaticStack* stack) {
    return stack->top == MAX_SIZE - 1; // Comprueba si el tope es igual al tamaño máximo menos uno
}

// Función para verificar si la pila está vacía
int isStackEmpty(struct StaticStack* stack) {
    return stack->top == -1; // Comprueba si el tope es -1 (pila vacía)
}

// Función para agregar un elemento a la pila
void push(struct StaticStack* stack, int item) {
    if (isStackFull(stack)) { // Primero verifica si la pila está llena
        printf("La pila está llena.\n");
        return; // Si está llena, no se puede agregar y termina la función
    }
    stack->items[++stack->top] = item; // Incrementa el tope y agrega el elemento
    printf("%d apilado.\n", item); // Imprime el elemento agregado
}

// Función para eliminar un elemento de la pila
int pop(struct StaticStack* stack) {
    if (isStackEmpty(stack)) { // Primero verifica si la pila está vacía
        printf("La pila está vacía.\n");
        return -1; // Si está vacía, no se puede eliminar y retorna -1
    }
    return stack->items[stack->top--]; // Retorna el elemento y decrementa el tope
}

// Función para mostrar los elementos de la pila
void displayStaticStack(struct StaticStack* stack) {
    if (isStackEmpty(stack)) { // Primero verifica si la pila está vacía
        printf("La pila está vacía.\n");
        return; // Si está vacía, no hay nada que mostrar y termina la función
    }
    printf("Elementos en la pila: ");
    for (int i = 0; i <= stack->top; i++) { // Recorre los elementos desde el fondo hasta el tope
        printf("%d ", stack->items[i]); // Imprime cada elemento de la pila
    }
    printf("\n"); // Imprime un salto de línea al final
}
