/*  Hecho por: Octavio Antonio Juárez Romero
    Matricula: 1577250a
    Materia: Estructura de Datos  */
#include <stdio.h>
#include "QueueWithHeader.h"

int main() {
    struct QueueHeader* queue = createQueue();
    int choice, data;

    while (1) {
        printf("\nMenú:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Mostrar Cola\n");
        printf("4. Salir\n");
        printf("Elige una opción: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Introduce el elemento para agregar a la cola: ");
                scanf("%d", &data);
                enqueue(queue, data);
                break;
            case 2:
                data = dequeue(queue);
                if (data != -1) {
                    printf("Elemento eliminado: %d\n", data);
                }
                break;
            case 3:
                displayQueue(queue);
                break;
            case 4:
                return 0;
            default:
                printf("Opción no válida.\n");
        }
    }
    return 0;
}
