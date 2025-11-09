#include <stdio.h>

int fibonacci(int n) {
    if (n == 0) return 0; // Caso base
    if (n == 1) return 1; // Caso base
    return fibonacci(n - 1) + fibonacci(n - 2); // Llamadas recursivas
}

int main() {
    int n = 10;
    printf("Serie de Fibonacci hasta el término %d:\n", n);
    for (int i = 0; i < n; i++)
        printf("%d ", fibonacci(i));
    printf("\n");
    return 0;
}