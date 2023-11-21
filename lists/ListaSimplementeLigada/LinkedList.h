#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdbool.h>

// Definición del nodo
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Prototipos de funciones
Node* createNode(int data);
void insertAtFront(Node** head, int data);
void deleteNode(Node** head, int key);
void displayList(Node* node);
bool searchNode(Node* head, int key);

#endif
