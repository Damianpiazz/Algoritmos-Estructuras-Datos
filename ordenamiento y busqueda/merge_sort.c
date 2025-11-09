#include <stdio.h>
#include <stdlib.h>

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
// Merge Sort para Vector
// -------------------------------
void merge_vector(Data arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    Data L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2) {
        if (L[i].valor <= R[j].valor) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort_vector(Data arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        merge_sort_vector(arr, l, m);
        merge_sort_vector(arr, m + 1, r);
        merge_vector(arr, l, m, r);
    }
}

// -------------------------------
// Merge Sort para Lista Enlazada
// -------------------------------
Nodo* merge_lista(Nodo* a, Nodo* b) {
    if (!a) return b;
    if (!b) return a;

    Nodo* result = NULL;

    if (a->valor <= b->valor) {
        result = a;
        result->siguiente = merge_lista(a->siguiente, b);
    } else {
        result = b;
        result->siguiente = merge_lista(a, b->siguiente);
    }

    return result;
}

void split_lista(Nodo* source, Nodo** frontRef, Nodo** backRef) {
    Nodo* slow = source;
    Nodo* fast = source->siguiente;

    while (fast) {
        fast = fast->siguiente;
        if (fast) {
            slow = slow->siguiente;
            fast = fast->siguiente;
        }
    }

    *frontRef = source;
    *backRef = slow->siguiente;
    slow->siguiente = NULL;
}

void merge_sort_lista(Nodo** headRef) {
    Nodo* head = *headRef;
    if (!head || !head->siguiente)
        return;

    Nodo* a;
    Nodo* b;

    split_lista(head, &a, &b);

    merge_sort_lista(&a);
    merge_sort_lista(&b);

    *headRef = merge_lista(a, b);
}