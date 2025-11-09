#include <stdio.h>

// -------------------------------
// Estructuras
// -------------------------------

typedef struct {
    int valor;
} Data;

typedef struct Nodo {
    int valor;
    struct Nodo* siguiente;
} Nodo;

// -------------------------------
// Funcion Insertion Sort para Vector
// -------------------------------
void insertion_sort_vector(Data arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i].valor;
        j = i - 1;
        while (j >= 0 && arr[j].valor > key) {
            arr[j + 1].valor = arr[j].valor;
            j--;
        }
        arr[j + 1].valor = key;
    }
}

// -------------------------------
// Funcion Insertion Sort para Lista Enlazada
// -------------------------------
void insertion_sort_lista(Nodo** cabeza_ref) {
    Nodo* sorted = NULL;
    Nodo* current = *cabeza_ref;

    while (current != NULL) {
        Nodo* next = current->siguiente;

        if (sorted == NULL || sorted->valor >= current->valor) {
            current->siguiente = sorted;
            sorted = current;
        } else {
            Nodo* temp = sorted;
            while (temp->siguiente != NULL && temp->siguiente->valor < current->valor) {
                temp = temp->siguiente;
            }
            current->siguiente = temp->siguiente;
            temp->siguiente = current;
        }
        current = next;
    }

    *cabeza_ref = sorted;
}