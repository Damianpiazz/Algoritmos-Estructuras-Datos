#include <stdio.h>
#include <string.h>
#include <ctype.h>

/*==============================================
1. Función f recursiva del programa Demo
==============================================*/
int f(int n){
    if(n==0) return 1;
    else if(n==1) return 2;
    else if(n==2) return 3;
    else return f(n-2)*f(n-4);
}

/*==============================================
2a. Imprimir palabra invertida
==============================================*/
void imprimirInvertida(const char *palabra, int len){
    if(len<0) return;
    putchar(palabra[len]);
    imprimirInvertida(palabra, len-1);
}

/*==============================================
2b. Contar palabras de una frase terminada en '.'
==============================================*/
int contarPalabras(const char *frase, int pos){
    if(frase[pos]=='.') return 0;
    if(frase[pos]==' ' && frase[pos+1]!=' ' && frase[pos+1]!='.') 
        return 1 + contarPalabras(frase,pos+1);
    return contarPalabras(frase,pos+1);
}

/*==============================================
3. Contar cantidad de vocales
==============================================*/
int contarVocales(const char *s, int pos){
    if(s[pos]=='\0') return 0;
    char c = tolower(s[pos]);
    if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u') 
        return 1 + contarVocales(s,pos+1);
    return contarVocales(s,pos+1);
}

/*==============================================
4. Serie de Fibonacci recursiva
==============================================*/
int fibonacci(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    return fibonacci(n-1)+fibonacci(n-2);
}

/*==============================================
5. Verificar si una palabra es palíndromo
==============================================*/
int esPalindromo(const char *s, int inicio, int fin){
    if(inicio>=fin) return 1;
    if(s[inicio]!=s[fin]) return 0;
    return esPalindromo(s, inicio+1, fin-1);
}

/*==============================================
6. Decimal a Binario
==============================================*/
void decimalABinario(int n){
    if(n==0) return;
    decimalABinario(n/2);
    printf("%d", n%2);
}

/*==============================================
7. Procedimiento Prueba recursivo
==============================================*/
void prueba_copia(int x, int y){
    if(y>0){
        x = x + 1;
        y = y - 1;
        printf("Copia: x=%d, y=%d\n",x,y);
        prueba_copia(x,y);
        printf("Copia final: x=%d, y=%d\n",x,y);
    }
}

void prueba_ref(int *x, int y){
    if(y>0){
        *x = *x + 1;
        y = y - 1;
        printf("Ref: x=%d, y=%d\n",*x,y);
        prueba_ref(x,y);
        printf("Ref final: x=%d, y=%d\n",*x,y);
    }
}

/*==============================================
8a. Sumar elementos de un vector
==============================================*/
int sumarVector(int v[], int n){
    if(n==0) return 0;
    return v[n-1]+sumarVector(v,n-1);
}

/*==============================================
8b. Contar múltiplos de 3
==============================================*/
int contarMultiplos3(int v[], int n){
    if(n==0) return 0;
    int cuenta = (v[n-1]%3==0)?1:0;
    return cuenta + contarMultiplos3(v,n-1);
}

/*==============================================
8c. Contar elementos pares en posiciones impares
==============================================*/
int paresPosImpar(int v[], int n, int pos){
    if(pos>=n) return 0;
    int cuenta = (pos%2==1 && v[pos]%2==0)?1:0;
    return cuenta + paresPosImpar(v,n,pos+1);
}

/*==============================================
PROGRAMA PRINCIPAL
==============================================*/
int main(){
    // 1. Demo función f
    int temp = f(8);
    printf("1. Valor de f(8) = %d\n", temp);

    // 2a. Imprimir palabra invertida
    char palabra[]="Algoritmo";
    printf("2a. Palabra invertida: ");
    imprimirInvertida(palabra, strlen(palabra)-1);
    printf("\n");

    // 2b. Contar palabras de frase
    char frase[]="Hola esto es una prueba.";
    int cant = contarPalabras(frase,0)+1; // +1 para la primera palabra
    printf("2b. Cantidad de palabras: %d\n", cant);

    // 3. Contar vocales
    char s[]="Práctica de Algoritmos";
    int vocales = contarVocales(s,0);
    printf("3. Cantidad de vocales: %d\n",vocales);

    // 4. Fibonacci
    printf("4. Serie Fibonacci (0-10): ");
    for(int i=0;i<=10;i++) printf("%d ", fibonacci(i));
    printf("\n");

    // 5. Palíndromo
    char palind[]="anana";
    printf("5. La palabra '%s' %s palindromo\n", palind,
        esPalindromo(palind,0,strlen(palind)-1)?"es":"no es");

    // 6. Decimal a binario
    int numero = 47;
    printf("6. %d en binario: ", numero);
    if(numero==0) printf("0");
    else decimalABinario(numero);
    printf("\n");

    // 7. Procedimiento prueba
    printf("7a. Pasando por copia:\n");
    prueba_copia(5,3);
    printf("7b. Pasando x por referencia:\n");
    int x = 5; 
    prueba_ref(&x,3);

    // 8. Recursión en arreglos
    int v[]={1,2,3,4,5,6,7,8,9};
    int n = sizeof(v)/sizeof(v[0]);
    printf("8a. Suma del vector: %d\n", sumarVector(v,n));
    printf("8b. Multiplos de 3: %d\n", contarMultiplos3(v,n));
    printf("8c. Pares en posiciones impares: %d\n", paresPosImpar(v,n,0));

    return 0;
}