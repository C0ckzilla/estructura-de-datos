#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

// Definición del nodo doblemente ligado
typedef struct DoublyNode {
    int data;
    struct DoublyNode* next;
    struct DoublyNode* prev;
} DoublyNode;

// Prototipos de funciones
DoublyNode* createDoublyNode(int data);
void insertAtFront(DoublyNode** head, int data);
void deleteNode(DoublyNode** head, int key);
void displayListForward(DoublyNode* head);
void displayListBackward(DoublyNode* tail);

#endif
