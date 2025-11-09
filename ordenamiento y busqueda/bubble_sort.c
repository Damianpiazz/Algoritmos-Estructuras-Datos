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
// Funcion Bubble Sort para Vector
// -------------------------------
void bubble_sort_vector(Data arr[], int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j].valor > arr[j + 1].valor) {
                temp = arr[j].valor;
                arr[j].valor = arr[j + 1].valor;
                arr[j + 1].valor = temp;
            }
        }
    }
}

// -------------------------------
// Funcion Bubble Sort para Lista Enlazada
// -------------------------------
void bubble_sort_lista(Nodo* cabeza) {
    if (!cabeza) return;

    int intercambiado;
    Nodo* ptr;
    Nodo* lptr = NULL;

    do {
        intercambiado = 0;
        ptr = cabeza;

        while (ptr->siguiente != lptr) {
            if (ptr->valor > ptr->siguiente->valor) {
                int temp = ptr->valor;
                ptr->valor = ptr->siguiente->valor;
                ptr->siguiente->valor = temp;
                intercambiado = 1;
            }
            ptr = ptr->siguiente;
        }
        lptr = ptr;
    } while (intercambiado);
}