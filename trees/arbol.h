#ifndef ARBOL_H
#define ARBOL_H
#pragma pack(1)

struct nodo { 
    int id;
    struct nodo *izq, *der;
};

struct nodo * crear_nodo (int);

#endif // ARBOL_H

