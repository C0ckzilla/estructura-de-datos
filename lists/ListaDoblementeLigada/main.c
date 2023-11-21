#include <stdio.h>
#include "DoublyLinkedList.h"

int main() {
    DoublyNode* head = NULL;
    DoublyNode* tail = NULL;
    int choice, data;

    while (1) {
        printf("\nOpciones:\n");
        printf("1. Insertar al inicio\n");
        printf("2. Eliminar nodo\n");
        printf("3. Mostrar lista hacia adelante\n");
        printf("4. Mostrar lista hacia atrás\n");
        printf("5. Salir\n");
        printf("Ingrese su elección: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Ingrese el valor a insertar: ");
                scanf("%d", &data);
                insertAtFront(&head, data);
                if (tail == NULL) tail = head;
                break;
            case 2:
                printf("Ingrese el valor a eliminar: ");
                scanf("%d", &data);
                deleteNode(&head, data);
                if (head == NULL) tail = NULL;
                break;
            case 3:
                displayListForward(head);
                break;
            case 4:
                if (tail != NULL) displayListBackward(tail);
                else printf("Lista vacía.\n");
                break;
            case 5:
                return 0;
            default:
                printf("Opción no válida.\n");
        }
    }
    return 0;
}
