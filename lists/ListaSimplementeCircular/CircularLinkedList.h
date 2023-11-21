#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

// Definición del nodo para la lista circular
typedef struct CircularNode {
    int data;
    struct CircularNode* next;
} CircularNode;

// Prototipos de funciones
CircularNode* createCircularNode(int data);
void insertAtFront(CircularNode** head, int data);
void deleteNode(CircularNode** head, int key);
void displayList(CircularNode* head);

#endif
