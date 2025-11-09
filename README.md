# Algoritmos-Estructuras-Datos

Este repositorio documenta e implementa los conceptos fundamentales de **Algoritmos y Estructuras de Datos (AED)**, cubriendo desde fundamentos y programación modular hasta estructuras estáticas, dinámicas y externas, así como técnicas algorítmicas avanzadas, complejidad, fórmulas de análisis y eficiencia.

---

## Índice de Contenidos

1. [Fundamentos de Programación y Estructuras de Control](#i-fundamentos-de-programación-y-estructuras-de-control)  
   1.1 [Concepto de Algoritmo](#1-concepto-de-algoritmo)  
   1.2 [Estructura de un Programa](#2-estructura-de-un-programa)  
2. [Programación Modular y Abstracción de Datos](#ii-programación-modular-y-abstracción-de-datos)  
   2.1 [Modularización](#1-modularización)  
   2.2 [Tipos Abstractos de Datos (TAD)](#2-tipos-abstractos-de-datos-tad)  
3. [Estructuras de Datos Estáticas](#iii-estructuras-de-datos-estáticas)  
4. [Estructuras de Datos Dinámicas](#iv-estructuras-de-datos-dinámicas)  
5. [Estructuras de Datos Externas (Archivos)](#v-estructuras-de-datos-externas-archivos)  
6. [Técnicas Algorítmicas Avanzadas](#vi-técnicas-algorítmicas-avanzadas)  
   6.1 [Recursión y Backtracking](#1-recursión-y-backtracking)  
   6.2 [Ordenamiento](#2-ordenamiento)  
   6.3 [Búsqueda](#3-búsqueda)  
7. [Clasificación de Estructuras de Datos](#vii-clasificación-de-estructuras-de-datos)  
8. [Complejidad y Eficiencia](#viii-complejidad-y-eficiencia)  

---

## I. Fundamentos de Programación y Estructuras de Control

Los programas se componen de **datos** e **instrucciones**, y la resolución de un problema requiere:

- **Estratégico:** Comprender el objetivo.  
- **Metodológico:** Determinar los pasos y la lógica de resolución.  
- **Herramental:** Elegir la representación de los pasos (pseudocódigo, diagramas, flujo).

### 1. Concepto de Algoritmo

Un **algoritmo** es un conjunto finito de acciones ordenadas que produce un resultado específico en tiempo limitado y sin ambigüedad.

**Propiedades:**

| Concepto    | Descripción |
|------------|-------------|
| Correcto   | Cumple la especificación y finaliza correctamente. |
| Eficiente  | Optimiza tiempo y espacio. |
| Claro      | Lógica comprensible y documentada. |
| Confiable  | Garantiza resultados válidos bajo condiciones definidas. |
| Mantenible | Permite modificaciones sin romper la integridad. |

### 2. Estructura de un Programa

1. **Cabecera:** Nombre del programa.  
2. **Declaraciones:** Constantes, variables, tipos, subprogramas.  
3. **Cuerpo Principal:** Secuencia de instrucciones.

#### 2.1 Variables

- **Localidad:** Locales y globales.  
- **Constantes:** Valores fijos.  
- **Operaciones:** Asignación, lectura y escritura.

#### 2.2 Estructuras de Control

| Estructura          | Mecánica |
|--------------------|----------|
| Secuencial          | Orden lineal. |
| Decisión Simple     | Evalúa condición; ejecuta si es verdadera. |
| Decisión Condicional | Rama verdadera o falsa. |
| Decisión Múltiple    | Varias opciones; ejecuta la primera que coincide. |
| Repetición Fija      | Itera n veces. |
| Repetición Condicional (Pre) | Evalúa antes de ejecutar; puede no ejecutarse. |
| Repetición Condicional (Post) | Ejecuta primero, luego evalúa; al menos una ejecución. |

- **Contadores y Acumuladores:** Variables que suman o contabilizan valores.

---

## II. Programación Modular y Abstracción de Datos

### 1. Modularización

- **Subprogramas:** Funciones (retornan valor) y procedimientos.  
- **Alcance de Variables:** Locales (temporales) y globales (persistentes).  
- **Pasaje de Parámetros:** Por valor o referencia.  

### 2. Tipos Abstractos de Datos (TAD)

Un **TAD** incluye:

- **Interfaz Pública:** Qué operaciones se pueden hacer y con qué parámetros.  
- **Operaciones Fundamentales:** Creación, modificación, consulta.

---

## III. Estructuras de Datos Estáticas

- **Registros:** Colecciones heterogéneas de campos.  
- **Vectores:** Elementos homogéneos accesibles por índice `i` con `1 ≤ i ≤ n`.  
- **Matrices:** Bidimensionales, accesibles mediante `(i, j)` con `1 ≤ i ≤ filas`, `1 ≤ j ≤ columnas`.

**Tamaño de matriz:** `|M| = filas × columnas`

---

## IV. Estructuras de Datos Dinámicas

- **Punteros:** Contienen dirección de memoria de otra variable.  
- **Listas Encadenadas:** Nodos con dato + puntero al siguiente.  
- **Listas Especiales:** Doblemente encadenadas, circulares.  
- **Pilas y Colas:** LIFO y FIFO respectivamente.

**Complejidad Temporal Básica:**

| Operación | Lista Simple | Lista Doble | Pila/Cola |
|-----------|-------------|------------|-----------|
| Inserción | O(1) cabeza / O(n) posición | O(1) | O(1) |
| Eliminación | O(1) cabeza / O(n) posición | O(1) | O(1) |
| Acceso    | O(n)       | O(n)      | O(1) |

---

## V. Estructuras de Datos Externas (Archivos)

- **Apertura, Lectura y Grabado**: Manejo de registros con punteros.  
- **Acceso Directo vs Secuencial:** Organización de Archivos Directos (AOD) permite inserciones sin reescritura completa.

**Posición de registro i:** `Pos = inicio + (i-1) × tamañoRegistro`

---

## VI. Técnicas Algorítmicas Avanzadas

### 1. Recursión y Backtracking

- **Recursión:** Resolución de un problema mediante subproblemas más pequeños.  
- **Caso Base:** Detiene la recursión.  
- **Pila de Ejecución:** Registros de Activación apilados.  
- **Backtracking:** Retroceso sistemático para explorar todas las soluciones posibles.

**Complejidad Recursiva:**  
Si `T(n)` es el tiempo de un algoritmo recursivo, frecuentemente se expresa como:

- `T(n) = a T(n/b) + f(n)` (División y Conquista)
- Método maestro: `T(n) ∈ O(n^log_b(a))` (si `f(n)` es polinómica y menor que `n^log_b(a)`)

### 2. Ordenamiento

| Método       | Complejidad Temporal | Complejidad Espacial |
|-------------|-------------------|-------------------|
| Burbuja     | O(n²)             | O(1)              |
| Inserción   | O(n²)             | O(1)              |
| Selección   | O(n²)             | O(1)              |
| Mezcla      | O(n log n)        | O(n)              |
| Rápido      | O(n log n) promedio, O(n²) peor caso | O(log n) recursivo |

### 3. Búsqueda

| Método       | Complejidad Temporal |
|-------------|-------------------|
| Secuencial  | O(n)              |
| Binaria     | O(log n)          |
| Indexada    | O(1) acceso directo |

**Fórmulas:**

- Promedio de búsqueda secuencial: `T_avg = (n+1)/2` comparaciones.  
- Búsqueda binaria: `T_max = log2(n)` comparaciones.

---

## VII. Clasificación de Estructuras de Datos

| Criterio            | Tipos                         | Descripción |
|--------------------|-------------------------------|-------------|
| Residencia/Permanencia | Internas / Externas          | RAM temporal o archivos permanentes. |
| Uso de Memoria        | Estáticas / Dinámicas        | Tamaño fijo vs tamaño variable. |
| Tipo de Datos         | Homogéneas / Heterogéneas   | Igual tipo o combinación de tipos. |

---

## VIII. Complejidad y Eficiencia

### 1. Análisis de Algoritmos

- **Tiempo de Ejecución:** Número de operaciones.  
- **Uso de Memoria:** Dependencia de la estructura y el algoritmo.  
- **Escalabilidad:** Capacidad de manejar grandes volúmenes de datos.

### 2. Notación Asintótica

- **O(f(n))**: Cota superior (peor caso)  
- **Ω(f(n))**: Cota inferior (mejor caso)  
- **Θ(f(n))**: Cota ajustada (caso promedio)

### 3. Fórmulas Clave

- Suma de n elementos: `S = Σ_{i=1}^{n} i = n(n+1)/2`  
- Factorial: `n! = Π_{i=1}^{n} i`  
- Complejidad recursiva divide y vencerás: `T(n) = a T(n/b) + f(n)`  
