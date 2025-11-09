# Recursión

## Descripción General

La **recursión** es una técnica fundamental en el diseño de algoritmos que permite resolver un problema en términos de instancias más pequeñas del mismo problema.  
Se presenta como una alternativa a la iteración, siendo especialmente útil para problemas que tienen una naturaleza recursiva.

---

## 1. Concepto Fundamental

### Resolución en Términos de Sí Mismo
Un algoritmo recursivo resuelve un problema **T** mediante una llamada a sí mismo con un problema más pequeño **T'**.

### Reducción de Complejidad
Cada autoinvocación reduce el tamaño del problema hasta llegar a un caso trivial que se puede resolver directamente.

### Definición Recursiva
Una definición recursiva incluye al objeto que se define como parte de su propia definición.

---

## 2. Componentes de un Algoritmo Recursivo

1. **Caso Recursivo:** Punto donde el algoritmo se llama a sí mismo. Puede haber uno o más casos recursivos.  
2. **Caso Base (Criterio de Terminación):** Condición que permite resolver el problema sin más llamadas recursivas. Garantiza que la recursión termine.  
3. **Reducción del Tamaño:** Cada llamada recursiva trabaja con un problema más pequeño que el anterior.

### Preguntas para construir una solución recursiva

- ¿Cómo representar el problema en términos de uno más pequeño?  
- ¿Cómo reducir el tamaño del problema en cada llamada?  
- ¿Cuál es el caso base?  
- ¿Qué garantiza que se alcanzará siempre el caso base?

---

## 3. Gestión de Memoria: Pila de Ejecución

La recursión utiliza un manejo especial de memoria, basado en la **pila de ejecución**.

| Concepto | Descripción |
|----------|-------------|
| Registro de Activación (R.A.) | Contiene parámetros, variables locales y espacio para el valor de retorno de cada llamada recursiva. |
| Pila de Ejecución | Los R.A. se apilan a medida que se realizan llamadas; el último llamado queda en el tope. |
| Backtracking | Tras alcanzar el caso base, los valores se retornan en orden inverso de las llamadas. |
| Liberación de Memoria | Al terminar cada llamada, su R.A. se desapila y la memoria se libera. |
| Stack Overflow | Si nunca se alcanza el caso base, se agota la memoria disponible y se produce un error. |

---

## 4. Tipos de Recursión

1. **Directa:** La función se llama a sí misma dentro de su propio cuerpo.  
   - Simple: Una sola llamada recursiva.  
   - Múltiple: Dos o más llamadas recursivas.  
   - Anidada: Llamada recursiva como argumento de otra llamada.  

2. **Indirecta (Cruzada):** La llamada recursiva ocurre a través de otra función. Ej.: A llama a B y B llama a A.

---

## 5. Ventajas y Desventajas

| Aspecto             | Solución Recursiva                                   | Solución Iterativa                  |
|---------------------|----------------------------------------------------|------------------------------------|
| Simplicidad/Elegancia | Soluciones elegantes y fáciles de entender       | Puede ser más difícil de desarrollar |
| Tiempo de Ejecución  | Puede requerir más tiempo                         | Generalmente más eficiente         |
| Uso de Memoria       | Cada llamada genera su propio R.A.               | Uso de memoria más eficiente       |
| Aplicación           | Ideal para problemas recursivos                   | Más eficiente en problemas simples |

---

## 6. Aplicación en Algoritmos y Diseño

### Técnicas de diseño relacionadas

- **Divide y Vencerás (Top-Down):** Divide el problema en subproblemas más pequeños y combina las soluciones. Ej.: Quicksort.  
- **Backtracking:** Genera soluciones mediante prueba y error, retrocediendo cuando un camino no es válido. Ej.: Problema de las N-Reinas.

### Complejidad
Algoritmos recursivos como Quicksort suelen tener complejidad **O(N log N)**.

### Usos específicos
- Matemática: cálculos combinatorios.  
- Programación funcional o lógica sin estructuras repetitivas.

---

## 7. Ejemplos de Aplicación Recursiva y Fórmulas

1. **Factorial de N:**  

$$
N! = \begin{cases} 
1 & \text{si } N = 0 \\
N \times (N-1)! & \text{si } N > 0 
\end{cases}
$$

2. **Potencia X^N:**  

$$
X^N = \begin{cases} 
1 & \text{si } N = 0 \\
X \times X^{N-1} & \text{si } N > 0
\end{cases}
$$

3. **Serie de Fibonacci:**  

$$
F(N) = \begin{cases} 
0 & \text{si } N = 0 \\
1 & \text{si } N = 1 \\
F(N-1) + F(N-2) & \text{si } N > 1
\end{cases}
$$

4. **Búsqueda Binaria (dicotómica):**  

$$
Buscar(A, low, high, X) = 
\begin{cases}
-1 & \text{si } low > high \\
\text{mid} & \text{si } A[mid] = X \\
Buscar(A, mid+1, high, X) & \text{si } A[mid] < X \\
Buscar(A, low, mid-1, X) & \text{si } A[mid] > X
\end{cases}
$$

5. **Suma de elementos con condición:**  
Ej.: Sumar pares y restar impares en una lista:

$$
Suma(L) = 
\begin{cases} 
0 & \text{si } L = \emptyset \\
L_1 + Suma(L') & \text{si } L_1 \text{ es par} \\
-L_1 + Suma(L') & \text{si } L_1 \text{ es impar}
\end{cases}
$$
