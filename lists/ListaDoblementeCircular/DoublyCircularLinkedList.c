#include <stdio.h>
#include <stdlib.h>
#include "DoublyCircularLinkedList.h"

// Crear un nuevo nodo doblemente circular
DoublyCircularNode* createDoublyCircularNode(int data) {
    DoublyCircularNode* newNode = (DoublyCircularNode*)malloc(sizeof(DoublyCircularNode));
    newNode->data = data;
    newNode->next = newNode;
    newNode->prev = newNode;
    return newNode;
}

// Insertar un nodo al inicio
void insertAtFront(DoublyCircularNode** head, int data) {
    DoublyCircularNode* newNode = createDoublyCircularNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        newNode->prev = (*head)->prev;
        (*head)->prev->next = newNode;
        (*head)->prev = newNode;
    }
    *head = newNode;
}

// Eliminar un nodo específico
void deleteNode(DoublyCircularNode** head, int key) {
    if (*head == NULL) return;
    DoublyCircularNode* temp = *head;
    do {
        if (temp->data == key) {
            if (temp->next == temp) {
                free(temp);
                *head = NULL;
                return;
            }
            temp->next->prev = temp->prev;
            temp->prev->next = temp->next;
            if (temp == *head) *head = temp->next;
            free(temp);
            return;
        }
        temp = temp->next;
    } while (temp != *head);
}

// Mostrar la lista
void displayList(DoublyCircularNode* head) {
    if (head == NULL) {
        printf("Lista vacía.\n");
        return;
    }
    DoublyCircularNode* temp = head;
    printf("Lista Doblemente Circular: ");
    do {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}
