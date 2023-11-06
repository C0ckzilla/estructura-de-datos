/*  Hecho por: Octavio Antonio Juárez Romero
    Matricula: 1577250a
    Materia: Estructura de Datos  */

#include <stdio.h>
#include <stdlib.h>
#include "DynamicStack.h"

// Función para crear una pila dinámica
struct DynamicStack* createDynamicStack() {
    struct DynamicStack* stack = (struct DynamicStack*)malloc(sizeof(struct DynamicStack)); // Asignación de memoria para la pila
    stack->top = NULL; // Inicialización del tope de la pila a NULL
    return stack; // Retorno del puntero a la nueva pila
}

// Función para insertar un elemento en la pila
void dPush(struct DynamicStack* stack, int item) {
    struct DNode* newNode = (struct DNode*)malloc(sizeof(struct DNode)); // Asignación de memoria para el nuevo nodo
    newNode->data = item; // Establecimiento del dato en el nuevo nodo
    newNode->next = stack->top; // Enlace del nuevo nodo con el tope actual de la pila
    stack->top = newNode; // Actualización del tope de la pila al nuevo nodo
    printf("%d apilado.\n", item); // Mensaje de confirmación
}

// Función para eliminar un elemento de la pila
int dPop(struct DynamicStack* stack) {
    if (stack->top == NULL) { // Verificación si la pila está vacía
        printf("La pila está vacía.\n");
        return -1; // Retorno de -1 si la pila está vacía
    }
    int item = stack->top->data; // Obtención del dato del tope de la pila
    struct DNode* temp = stack->top; // Almacenamiento temporal del tope actual
    stack->top = stack->top->next; // Actualización del tope de la pila al siguiente nodo
    free(temp); // Liberación de la memoria del nodo eliminado
    return item; // Retorno del dato del nodo eliminado
}

// Función para mostrar los elementos de la pila
void displayDynamicStack(struct DynamicStack* stack) {
    if (stack->top == NULL) { // Verificación si la pila está vacía
        printf("La pila está vacía.\n");
        return; // Salida de la función si la pila está vacía
    }
    printf("Elementos en la pila: ");
    struct DNode* temp = stack->top; // Inicio del recorrido desde el tope de la pila
    while (temp != NULL) { // Recorrido de todos los elementos de la pila
        printf("%d ", temp->data); // Impresión del dato del nodo actual
        temp = temp->next; // Movimiento al siguiente nodo
    }
    printf("\n"); // Salto de línea al final de la impresión de los elementos
}
