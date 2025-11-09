#include <stdio.h>

int dividir(int a, int b, int *resultado) {
    if (b == 0) return -1; // error
    *resultado = a / b;
    return 0; // exito
}

int main() {
    int res;
    if (dividir(10, 0, &res) != 0) {
        printf("Error: División por cero\n");
    } else {
        printf("Resultado: %d\n", res);
    }
    return 0;
}