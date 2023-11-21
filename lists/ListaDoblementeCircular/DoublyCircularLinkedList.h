#ifndef DOUBLYCIRCULARLINKEDLIST_H
#define DOUBLYCIRCULARLINKEDLIST_H

// Definición del nodo para la lista doblemente circular
typedef struct DoublyCircularNode {
    int data;
    struct DoublyCircularNode* next;
    struct DoublyCircularNode* prev;
} DoublyCircularNode;

// Prototipos de funciones
DoublyCircularNode* createDoublyCircularNode(int data);
void insertAtFront(DoublyCircularNode** head, int data);
void deleteNode(DoublyCircularNode** head, int key);
void displayList(DoublyCircularNode* head);

#endif
