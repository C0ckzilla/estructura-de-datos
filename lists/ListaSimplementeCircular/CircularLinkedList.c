#include <stdio.h>
#include <stdlib.h>
#include "CircularLinkedList.h"

// Crear un nuevo nodo circular
CircularNode* createCircularNode(int data) {
    CircularNode* newNode = (CircularNode*)malloc(sizeof(CircularNode));
    newNode->data = data;
    newNode->next = newNode;  // Apunta a sí mismo para formar un círculo
    return newNode;
}

// Insertar un nodo al inicio
void insertAtFront(CircularNode** head, int data) {
    CircularNode* newNode = createCircularNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        CircularNode* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
    *head = newNode;
}

// Eliminar un nodo específico
void deleteNode(CircularNode** head, int key) {
    if (*head == NULL) return;
    CircularNode *temp = *head, *prev;
    if (temp->data == key && temp->next == *head) {
        free(temp);
        *head = NULL;
        return;
    }
    do {
        prev = temp;
        temp = temp->next;
        if (temp->data == key) {
            prev->next = temp->next;
            if (temp == *head) *head = prev->next;
            free(temp);
            return;
        }
    } while (temp != *head);
}

// Mostrar la lista
void displayList(CircularNode* head) {
    if (head == NULL) {
        printf("Lista vacía.\n");
        return;
    }
    CircularNode* temp = head;
    printf("Lista Circular: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
