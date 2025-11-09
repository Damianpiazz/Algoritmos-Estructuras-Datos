#include <stdio.h>

// Ejercicio 1: Cálculo de sueldo de un empleado
void ejercicio1() {
    char nombre[50];
    double sueldoBasico, premio, comida, viaticos;
    int ausentes;
    double descuentoOS, descuentoLey, descuentoJubilacion, descuentoAusentes, remunerativo, sueldoNeto;
    
    printf("Ingrese nombre del empleado: ");
    scanf("%49s", nombre);
    printf("Ingrese Sueldo Basico, Premio, Comida, Viaticos y Ausentes: ");
    scanf("%lf %lf %lf %lf %d", &sueldoBasico, &premio, &comida, &viaticos, &ausentes);
    
    remunerativo = sueldoBasico + premio;
    descuentoOS = remunerativo * 0.03;
    descuentoLey = remunerativo * 0.03;
    descuentoJubilacion = remunerativo * 0.11;
    descuentoAusentes = ausentes * 50; // ejemplo de monto fijo
    
    sueldoNeto = sueldoBasico + premio + comida + viaticos - descuentoOS - descuentoLey - descuentoJubilacion - descuentoAusentes;
    
    printf("Recibo de Sueldo de %s: %.2lf\n", nombre, sueldoNeto);
}

// Ejercicio 2: Recibo de uso de computadora
void ejercicio2() {
    int minutos, hojas;
    double cobroMinutos, cobroHojas, seguro, total;
    
    printf("Ingrese minutos usados y hojas impresas: ");
    scanf("%d %d", &minutos, &hojas);
    
    cobroMinutos = minutos * 10;
    cobroHojas = hojas * 15;
    seguro = 5 * (minutos * 0.01);
    
    total = cobroMinutos + cobroHojas + seguro;
    printf("Total a pagar: %.2lf\n", total);
}

// Ejercicio 3: Suma de tres números y comparación
void ejercicio3() {
    double a, b, c;
    printf("Ingrese tres numeros: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    
    if(a+b == c || a+c == b || b+c == a)
        printf("Iguales\n");
    else
        printf("Distintos\n");
}

// Ejercicio 4: Calculadora simple
void ejercicio4() {
    double a, b;
    char op;
    printf("Ingrese dos numeros y operacion (+ - * /): ");
    scanf("%lf %lf %c", &a, &b, &op);
    
    switch(op) {
        case '+': printf("Resultado: %.2lf\n", a+b); break;
        case '-': printf("Resultado: %.2lf\n", a-b); break;
        case '*': printf("Resultado: %.2lf\n", a*b); break;
        case '/': 
            if(b != 0) printf("Resultado: %.2lf\n", a/b);
            else printf("Division por cero no permitida.\n");
            break;
        default: printf("Operacion no valida.\n");
    }
}

// Ejercicio 5: Mayor de dos números
void ejercicio5() {
    double x, y;
    printf("Ingrese dos numeros: ");
    scanf("%lf %lf", &x, &y);

    if(x > y) 
        printf("Mayor: %.2lf\n", x);
    else 
        printf("Mayor: %.2lf\n", y);
}

// Ejercicio 6: Detectar errores de sintaxis simulados
void ejercicio6() {
    printf("Ejercicio 6: Analisis de errores de sintaxis (describir, no codificar)\n");
    printf("Se deben analizar bloques de SI/SINO mal escritos y corregirlos en pseudocodigo.\n");
}

// Ejercicio 7: Calculadora simple con CASE (switch)
void ejercicio7() {
    double a, b;
    char op;
    printf("Ingrese dos numeros y operador (+ - * /): ");
    scanf("%lf %lf %c", &a, &b, &op);

    switch(op) {
        case '+': printf("Suma: %.2lf\n", a+b); break;
        case '-': printf("Resta: %.2lf\n", a-b); break;
        case '*': printf("Multiplicacion: %.2lf\n", a*b); break;
        case '/': 
            if(b != 0) printf("Division: %.2lf\n", a/b);
            else printf("Error: division por cero\n");
            break;
        default: printf("Operacion no valida\n");
    }
}

// Ejercicio 8: Valores de variables paso a paso
void ejercicio8() {
    double A = 3625.25, B = 0.2568, OP;
    
    OP = (A + B)/152;
    printf("OP= %.5lf\n", OP);
    
    OP = (OP * A) - B;
    printf("OP actualizado= %.5lf\n", OP);
    
    B = OP * 56;
    printf("B= %.5lf\n", B);
    
    if(OP >= 45)
        printf("Camino 1: A= %.2lf, B= %.2lf\n", A, B);
    else
        printf("Camino 2: A= %.2lf, OP= %.2lf\n", A, OP);

    printf("A= %.2lf, B= %.2lf, OP^3= %.2lf\n", A, B, OP*OP*OP);
}

// Ejercicio 9: Comparación I/J = K/L
void ejercicio9() {
    double I, J, K, L;
    printf("Ingrese I, J, K, L: ");
    scanf("%lf %lf %lf %lf", &I, &J, &K, &L);

    if(J == 0 || L == 0) {
        printf("No se puede realizar la division, divisor cero.\n");
        return;
    }

    if(I/J == K/L) 
        printf("Son iguales\n");
}

// Ejercicio 10: Atleta y pérdida de peso
void ejercicio10() {
    double peso, longitudCircuito, tiempo;
    double gramosPerdidos;
    
    printf("Ingrese peso del corredor (g), longitud del circuito (m), tiempo empleado (s): ");
    scanf("%lf %lf %lf", &peso, &longitudCircuito, &tiempo);
    
    gramosPerdidos = (100.0/50.0) * longitudCircuito;
    double pesoFinal = peso - gramosPerdidos;
    
    printf("Gramos perdidos: %.2lf\nPeso final: %.2lf\n", gramosPerdidos, pesoFinal);

    if(gramosPerdidos > 450)
        printf("Necesita vitamina A y C\n");
    else if(gramosPerdidos > 300)
        printf("Necesita vitamina A\n");

    if(tiempo < 25)
        printf("Mejoro record olimpico\n");
    if(tiempo < 15)
        printf("Mejoro record panamericano\n");
}

// Ejercicio 11: Bancos y alumnos
void ejercicio11() {
    int bancos, alumnos;
    printf("Ingrese cantidad de bancos y cantidad de alumnos: ");
    scanf("%d %d", &bancos, &alumnos);

    if(bancos >= alumnos)
        printf("Bancos suficientes\n");
    else
        printf("Faltan %d bancos\n", alumnos - bancos);
}

// Ejercicio 12: Mayor de tres números
void ejercicio12() {
    double x, y, z;
    printf("Ingrese tres numeros: ");
    scanf("%lf %lf %lf", &x, &y, &z);

    double mayor = x;
    if(y > mayor) mayor = y;
    if(z > mayor) mayor = z;

    printf("Mayor: %.2lf\n", mayor);
}

// Ejercicio 13: Mayor de tres números usando menor cantidad de condiciones
void ejercicio13() {
    double a, b, c;
    printf("Ingrese tres numeros: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    double mayor = (a > b) ? a : b;
    mayor = (mayor > c) ? mayor : c;

    printf("Mayor (usando menos condiciones): %.2lf\n", mayor);
}

// Ejercicio 14: Valores de variables en operaciones consecutivas
void ejercicio14() {
    double A = 3625.25, B = 0.2568, OP;

    OP = (A + B)/152;
    printf("OP= %.5lf\n", OP);

    OP = (OP*A) - B;
    printf("OP actualizado= %.5lf\n", OP);

    B = OP*56;
    printf("B= %.5lf\n", B);

    if(OP >= 45)
        printf("Camino 1: A= %.2lf, B= %.2lf\n", A, B);
    else
        printf("Camino 2: A= %.2lf, OP= %.2lf\n", A, OP);

    printf("A= %.2lf, B= %.2lf, OP^3= %.2lf\n", A, B, OP*OP*OP);
}

// Ejercicio 15: Calculadora con caso de caracteres y division por cero
void ejercicio15() {
    double x, y;
    char op;
    printf("Ingrese dos numeros y operador (+ - * /): ");
    scanf("%lf %lf %c", &x, &y, &op);

    switch(op) {
        case '+': printf("Suma: %.2lf\n", x+y); break;
        case '-': printf("Resta: %.2lf\n", x-y); break;
        case '*': printf("Multiplicacion: %.2lf\n", x*y); break;
        case '/': 
            if(y != 0) printf("Division: %.2lf\n", x/y);
            else printf("Error: division por cero\n");
            break;
        default: printf("Operacion no valida\n");
    }
}

// Ejercicio 16: Ticket compra dólares con comisiones
void ejercicio16() {
    double dolares, valorDolar, montoTotal, comision = 0;
    printf("Ingrese cantidad de dolares a comprar y valor del dolar: ");
    scanf("%lf %lf", &dolares, &valorDolar);

    if(dolares > 501 && dolares <= 1500) comision = 0.02;
    else if(dolares > 1501 && dolares <= 3500) comision = 0.025;
    else if(dolares > 3500) comision = 0.04;

    montoTotal = dolares*valorDolar*(1+comision);

    printf("Cantidad de dolares: %.2lf\n", dolares);
    printf("Valor del dolar: %.2lf\n", valorDolar);
    printf("Monto de comision: %.2lf\n", dolares*valorDolar*comision);
    printf("Monto total a pagar: %.2lf\n", montoTotal);
}


// Función main para probar ejercicios
int main() {

    ejercicio1();
    ejercicio2();
    ejercicio3();
    ejercicio4();
    ejercicio5();
    ejercicio6();
    ejercicio7();
    ejercicio8();
    ejercicio9();
    ejercicio10();
    ejercicio11();
    ejercicio12();
    ejercicio13();
    ejercicio14();
    ejercicio15();
    ejercicio16();

    return 0;
}
