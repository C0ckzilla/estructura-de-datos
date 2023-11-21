#include <stdio.h>
#include "CircularLinkedList.h"

int main() {
    CircularNode* head = NULL;
    int choice, data;

    while (1) {
        printf("\nOpciones:\n");
        printf("1. Insertar al inicio\n");
        printf("2. Eliminar nodo\n");
        printf("3. Mostrar lista\n");
        printf("4. Salir\n");
        printf("Ingrese su elección: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Ingrese el valor a insertar: ");
                scanf("%d", &data);
                insertAtFront(&head, data);
                break;
            case 2:
                printf("Ingrese el valor a eliminar: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                return 0;
            default:
                printf("Opción no válida.\n");
        }
    }
    return 0;
}
