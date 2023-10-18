/*  Hecho por: Octavio Antonio Juárez Romero
    Matricula: 1577250a
    Materia: Estructura de Datos  */
#include <stdio.h>
#include "StaticStack.h"

int main() {
    struct StaticStack* stack = createStaticStack();
    int choice, data;

    while (1) {
        printf("\nMenú:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Mostrar Pila\n");
        printf("4. Salir\n");
        printf("Elige una opción: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Introduce el elemento para apilar: ");
                scanf("%d", &data);
                push(stack, data);
                break;
            case 2:
                data = pop(stack);
                if (data != -1) {
                    printf("Elemento desapilado: %d\n", data);
                }
                break;
            case 3:
                displayStaticStack(stack);
                break;
            case 4:
                return 0;
            default:
                printf("Opción no válida.\n");
        }
    }
    return 0;
}
