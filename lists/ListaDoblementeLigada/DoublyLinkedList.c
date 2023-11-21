#include <stdio.h>
#include <stdlib.h>
#include "DoublyLinkedList.h"

// Crear un nuevo nodo doblemente ligado
DoublyNode* createDoublyNode(int data) {
    DoublyNode* newNode = (DoublyNode*)malloc(sizeof(DoublyNode));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Insertar un nodo al inicio
void insertAtFront(DoublyNode** head, int data) {
    DoublyNode* newNode = createDoublyNode(data);
    newNode->next = *head;
    if (*head != NULL) (*head)->prev = newNode;
    *head = newNode;
}

// Eliminar un nodo específico
void deleteNode(DoublyNode** head, int key) {
    DoublyNode* temp = *head;
    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        if (*head != NULL) (*head)->prev = NULL;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key) temp = temp->next;
    if (temp == NULL) return;
    if (temp->next != NULL) temp->next->prev = temp->prev;
    if (temp->prev != NULL) temp->prev->next = temp->next;
    free(temp);
}

// Mostrar la lista hacia adelante
void displayListForward(DoublyNode* head) {
    DoublyNode* temp = head;
    printf("Lista hacia adelante: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Mostrar la lista hacia atrás
void displayListBackward(DoublyNode* tail) {
    DoublyNode* temp = tail;
    printf("Lista hacia atrás: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}
