# Métodos de Ordenamiento y Búsqueda

## Descripción General

Los **métodos de ordenamiento** y **búsqueda** son técnicas fundamentales para organizar y recuperar información en estructuras de datos.  

- **Ordenamiento:** Disponer los datos en un orden específico (numérico creciente/decreciente, alfabético, etc.).  
- **Búsqueda:** Recuperar un dato específico dentro de un conjunto de datos.

El análisis de eficiencia considera **tiempo de ejecución** (operaciones realizadas) y **uso de memoria** (espacio requerido por el algoritmo).

---

## I. Métodos de Ordenamiento (Sorting Algorithms)

### 1. Consideraciones de Eficiencia y Clasificación

- **Eficiencia:** Depende del número de operaciones (comparaciones + asignaciones/intercambios).  
- **Clasificación por Ubicación y Memoria:**
  - **Internos:** Operan sobre datos en memoria principal (RAM).  
  - **Externos:** Operan sobre datos en memoria secundaria.  
  - **In-Situ o Directo:** Ordena los datos en la misma estructura.  
  - **Con Auxiliar:** Usa estructuras adicionales, duplicando el uso de memoria.  
- **Clasificación por Complejidad:**
  - **Simples:** Lógica sencilla, complejidad O(N²). Ej.: Selección, Burbuja, Inserción.  
  - **Avanzados:** Algoritmos recursivos y eficientes. Ej.: Quicksort, Mergesort, Shell.  

---

### 2. Métodos Simples

#### A. Método de Selección (Directo o In-Situ)
- **Principio:** Selecciona el mínimo elemento de cada pasada y lo coloca en la posición correspondiente.  
- **Mecanismo:** Compara el elemento en la posición I con los elementos posteriores (J) y realiza intercambios si es necesario.  
- **Complejidad:** O(N²). Total de comparaciones: (N² − N)/2.  

#### B. Método de Intercambio (Burbuja)
- **Principio:** Compara elementos adyacentes e intercambia los desordenados, haciendo que los mayores "floten" hacia el final.  
- **Optimización:** Se puede usar una bandera para detener el proceso si no hay intercambios en una pasada.  
- **Eficiencia Comparada:** Promedio ~ N²/4 comparaciones, más eficiente que Selección para N grande.  

#### C. Método de Inserción
- **Principio:** Inserta cada elemento en su posición correcta, desplazando los anteriores si es necesario.  
- **Mecanismo:** Se compara con los elementos anteriores y se realiza un corrimiento hasta encontrar el lugar correcto.  
- **Complejidad:** O(N²).  

---

### 3. Métodos Avanzados

#### Quicksort
- **Principio:** Algoritmo recursivo basado en **Divide y Vencerás**. Divide el vector en subrangos y los ordena recursivamente.  
- **Complejidad:** O(N log N), altamente eficiente para grandes conjuntos de datos.  

---

## II. Métodos de Búsqueda

### 1. Búsqueda Secuencial (Lineal)
- **Principio:** Recorrer el arreglo y comparar cada elemento con la clave buscada.  
- **Implementación:**  
  - **Incondicional:** Recorre todo el arreglo.  
  - **Condicional:** Se detiene si el elemento se encuentra antes de llegar al final.  
- **Eficiencia:** Promedio (N+1)/2 comparaciones. Ineficiente para conjuntos grandes.  

---

### 2. Búsqueda Binaria (Dicotómica)
- **Requisito:** Conjunto previamente **ordenado**.  
- **Principio:** Técnica "Divide y Vencerás". Divide el arreglo en la mitad y compara con el elemento central.  
- **Mecanismo:**  
  1. Calcular índice central: `mitad = ENT((primero + ultimo) / 2)`.  
  2. Comparar el dato buscado con el elemento central.  
  3. Si es mayor, buscar en la mitad superior; si es menor, en la mitad inferior.  
  4. Repetir hasta encontrar el elemento o hasta que no queden elementos (caso base: subvector vacío).  
- **Eficiencia:** Logarítmica O(log N). Para N grande, log₂(N) << N.  
- **Complejidad:** Peor caso ~ log₂(N+1) comparaciones.  

---

## 3. Comparación General

| Método | Tipo | Complejidad | Memoria | Uso recomendado |
|--------|------|------------|---------|----------------|
| Selección | Simple | O(N²) | In-Situ | Pequeños vectores, poca memoria |
| Burbuja | Simple | O(N²) | In-Situ | Vectores medianos, sencillo de implementar |
| Inserción | Simple | O(N²) | In-Situ | Listas parcialmente ordenadas |
| Quicksort | Avanzado | O(N log N) | Recursivo | Grandes conjuntos de datos |
| Búsqueda Lineal | Simple | O(N) | In-Situ | Datos desordenados o pequeños |
| Búsqueda Binaria | Avanzado | O(log N) | In-Situ | Datos ordenados, conjuntos grandes |

---

## 4. Conclusión

- Los **métodos de ordenamiento simples** son fáciles de implementar pero no eficientes para grandes conjuntos.  
- Los **algoritmos avanzados** como Quicksort permiten ordenar grandes cantidades de datos de forma rápida y eficiente.  
- La **búsqueda binaria** es muy eficiente, pero requiere previamente un conjunto ordenado.  
- La elección del método depende del **tamaño de los datos**, la **memoria disponible** y la **complejidad de implementación**.
