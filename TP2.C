#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// -------------------- Funciones básicas TP2 --------------------

// Ejercicio 1: Tabla de multiplicar
void tablaMultiplicar() {
    int num;
    printf("Ingrese un número para generar su tabla de multiplicar: ");
    scanf("%d", &num);
    printf("Tabla del %d:\n", num);
    for(int i=1;i<=20;i++)
        printf("%d x %d = %d\n", num, i, num*i);
}

// Ejercicio 2: Promedio de notas de 40 alumnos
void promedioNotas() {
    int notas[40], suma=0;
    for(int i=0;i<40;i++){
        printf("Ingrese nota del alumno %d: ", i+1);
        scanf("%d",&notas[i]);
        suma += notas[i];
    }
    printf("Promedio de notas: %d\n", suma/40);
}

// Ejercicio 3: Porcentaje de aprobados y promedio
void porcentajeAprobados() {
    int notas[40], sumaAprob=0, aprobados=0;
    for(int i=0;i<40;i++){
        printf("Ingrese nota del alumno %d: ", i+1);
        scanf("%d",&notas[i]);
        if(notas[i]>=6){
            sumaAprob += notas[i];
            aprobados++;
        }
    }
    double porcentaje = (aprobados*100.0)/40;
    printf("Porcentaje de aprobados: %.2lf%%\n", porcentaje);
    if(aprobados>0)
        printf("Promedio de aprobacion: %d\n", sumaAprob/aprobados);
}

// Ejercicio 4: Ciudad con mayor cantidad de chicos
void ciudadMayorChicos() {
    int ciudad1=1000, ciudad2=1500, ciudad3=1530;
    int max = ciudad1;
    int ciudad=1;
    if(ciudad2>max){ max=ciudad2; ciudad=2;}
    if(ciudad3>max){ max=ciudad3; ciudad=3;}
    printf("Ciudad con mayor cantidad de chicos menores de 10 años: %d\n", ciudad);
}

// Ejercicio 5: Maximo de N numeros
void maxDeNumeros() {
    int N, num, max;
    printf("Ingrese la cantidad de números: ");
    scanf("%d", &N);
    printf("Ingrese el primer número: ");
    scanf("%d", &max);
    for(int i=1;i<N;i++) {
        printf("Ingrese el siguiente número: ");
        scanf("%d", &num);
        if(num > max) max = num;
    }
    printf("El máximo es: %d\n", max);
}

// Ejercicio 6: Potencias de M
void potenciasDeM() {
    int M, N;
    printf("Ingrese M y N: ");
    scanf("%d %d", &M, &N);
    printf("Potencias de %d:\n", M);
    for(int i=0;i<N;i++) {
        int pot=1;
        for(int j=0;j<i;j++) pot*=M;
        printf("%d ", pot);
    }
    printf("\n");
}

// Ejercicio 7: Suma de primeras N potencias
void sumaPotencias() {
    int M,N;
    printf("Ingrese M y N: ");
    scanf("%d %d",&M,&N);
    int suma=0;
    for(int i=0;i<N;i++){
        int pot=1;
        for(int j=0;j<i;j++) pot*=M;
        suma += pot;
    }
    printf("Suma de las primeras %d potencias de %d: %d\n", N, M, suma);
}

// Ejercicio 8: Potencias de P desde Q hasta R
void potenciasRango() {
    int P,Q,R;
    printf("Ingrese P, Q, R: ");
    scanf("%d %d %d",&P,&Q,&R);
    printf("Potencias de %d desde %d hasta %d:\n", P,Q,R);
    for(int i=Q;i<=R;i++){
        int pot=1;
        for(int j=0;j<i;j++) pot*=P;
        printf("%d ", pot);
    }
    printf("\n");
}

// Ejercicio 10: Divisores de un número
void divisores() {
    int n;
    printf("Ingrese un número: ");
    scanf("%d", &n);
    printf("Divisores de %d menores que él:\n", n);
    for(int i=1;i<=n/2;i++) if(n % i == 0) printf("%d ", i);
    printf("\n");
}

// Ejercicio 11: Raices de segundo grado
void raicesSegundoGrado() {
    double a,b,c,dis,r1,r2;
    printf("Ingrese a, b, c de la ecuacion ax^2 + bx + c = 0: ");
    scanf("%lf %lf %lf",&a,&b,&c);
    dis = b*b - 4*a*c;
    if(dis < 0) printf("No existen raíces reales.\n");
    else {
        r1 = (-b + sqrt(dis))/(2*a);
        r2 = (-b - sqrt(dis))/(2*a);
        printf("Raices: %.2lf , %.2lf\n", r1,r2);
    }
}

// Ejercicio 4 TP02: Dibujo pirámide
void piramide() {
    for(int i=1;i<=5;i++) {
        for(int j=1;j<=i;j++) printf("* ");
        printf("\n");
    }
}

// Ejercicio 6 TP02: Invertir cadena
void invertirCadena() {
    char s[100];
    printf("Ingrese una cadena: ");
    getchar();
    fgets(s,100,stdin);
    s[strcspn(s,"\n")]=0;
    int len=strlen(s);
    printf("Cadena invertida: ");
    for(int i=len-1;i>=0;i--) printf("%c",s[i]);
    printf("\n");
}

// Ejercicio 7: Eliminar espacios al inicio
void eliminarEspaciosInicio() {
    char s[100], res[100];
    printf("Ingrese una cadena: ");
    getchar();
    fgets(s,100,stdin);
    int i=0,j=0;
    while(s[i]==' ' || s[i]=='\t') i++;
    while(s[i]!='\0') res[j++]=s[i++];
    res[j]='\0';
    printf("Cadena sin espacios al inicio: '%s'\n", res);
}

// Ejercicio 8: Eliminar espacios al final
void eliminarEspaciosFinal() {
    char s[100];
    printf("Ingrese una cadena: ");
    getchar();
    fgets(s,100,stdin);
    s[strcspn(s,"\n")]=0;
    int i=strlen(s)-1;
    while(i>=0 && (s[i]==' ' || s[i]=='\t')) s[i--]='\0';
    printf("Cadena sin espacios al final: '%s'\n", s);
}

// Ejercicio: Resto por restas sucesivas
void restoPorRestas() {
    int A,B,R;
    printf("Hallar el resto de la división entre dos números enteros positivos\n");
    printf("Ingrese A: "); scanf("%d",&A);
    printf("Ingrese B: "); scanf("%d",&B);
    R = A;
    while(R >= B) R = R - B;
    printf("El resto de dividir %d por %d es %d\n", A,B,R);
}

// Ejercicio 13: Bucles anidados ejemplo a
void buclesAnidadosA() {
    for(int i=1;i<=5;i++){
        printf("i=%d: ", i);
        for(int j=i;j>=1;j-=2) printf("%d ", j);
        printf("\n");
    }
}

// Ejercicio 13: Bucles anidados ejemplo b
void buclesAnidadosB() {
    for(int i=3;i>=1;i--){
        for(int j=1;j<=i;j++){
            for(int k=i;k>=j;k--){
                printf("i=%d j=%d k=%d\n", i,j,k);
            }
        }
    }
}

// Ejercicio 13: Bucles anidados ejemplo c
void buclesAnidadosC() {
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            for(int k=i;k<=j;k++){
                printf("i=%d j=%d k=%d\n", i,j,k);
            }
        }
    }
}

// Ejercicio 16: Conteo palabras y letras 'cas'
void conteoPalabrasCas() {
    char texto[500], *palabra;
    int total=0, contCas=0, maxLen=0;
    printf("Ingrese un texto terminado en punto: ");
    getchar();
    fgets(texto,500,stdin);
    texto[strcspn(texto,"\n")]=0;
    palabra = strtok(texto," .\t\n");
    while(palabra != NULL) {
        total++;
        int len = strlen(palabra);
        if(len > maxLen) maxLen = len;
        if(len>=3 && (strstr(palabra+2,"cas")!=NULL)) contCas++;
        palabra = strtok(NULL," .\t\n");
    }
    double porcentaje = (total>0)?(contCas*100.0/total):0;
    printf("Total palabras: %d, Palabras con 'cas' a partir de la tercera letra: %d, porcentaje: %.2lf%%\n",
           total, contCas, porcentaje);
    printf("Longitud de palabra mas larga: %d\n", maxLen);
}

// -------------------- Menu principal --------------------
int main() {
    int opcion;
    do {
        printf("\n=== TP2 - Estructuras de Control Completo ===\n");
        printf("1) Tabla de multiplicar\n");
        printf("2) Promedio de notas de 40 alumnos\n");
        printf("3) Porcentaje de aprobados\n");
        printf("4) Ciudad con mayor cantidad de chicos\n");
        printf("5) Maximo de N numeros\n");
        printf("6) Potencias de M\n");
        printf("7) Suma de primeras N potencias\n");
        printf("8) Potencias de P desde Q hasta R\n");
        printf("9) Divisores de un numero\n");
        printf("10) Raices cuadradas de segundo grado\n");
        printf("11) Piramide de asteriscos\n");
        printf("12) Invertir cadena\n");
        printf("13) Eliminar espacios al inicio\n");
        printf("14) Eliminar espacios al final\n");
        printf("15) Resto por restas sucesivas\n");
        printf("16) Bucles anidados ejemplo a\n");
        printf("17) Bucles anidados ejemplo b\n");
        printf("18) Bucles anidados ejemplo c\n");
        printf("19) Conteo palabras con 'cas'\n");
        printf("0) Salir\n");
        printf("Seleccione opcion: ");
        scanf("%d",&opcion);

        switch(opcion){
            case 1: tablaMultiplicar(); break;
            case 2: promedioNotas(); break;
            case 3: porcentajeAprobados(); break;
            case 4: ciudadMayorChicos(); break;
            case 5: maxDeNumeros(); break;
            case 6: potenciasDeM(); break;
            case 7: sumaPotencias(); break;
            case 8: potenciasRango(); break;
            case 9: divisores(); break;
            case 10: raicesSegundoGrado(); break;
            case 11: piramide(); break;
            case 12: invertirCadena(); break;
            case 13: eliminarEspaciosInicio(); break;
            case 14: eliminarEspaciosFinal(); break;
            case 15: restoPorRestas(); break;
            case 16: buclesAnidadosA(); break;
            case 17: buclesAnidadosB(); break;
            case 18: buclesAnidadosC(); break;
            case 19: conteoPalabrasCas(); break;
            case 0: printf("Saliendo...\n"); break;
            default: printf("Opcion invalida.\n");
        }
    } while(opcion != 0);
    return 0;
}
