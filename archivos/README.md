# Métodos de Acceso y Organización de Archivos

## 1. Introducción

Los **archivos** son colecciones de datos del mismo tipo, relacionados entre sí, que se almacenan en una unidad de **memoria secundaria o auxiliar** (como disco rígido, cinta o dispositivo externo).  
Esto permite **preservar la información de forma permanente**, incluso después de que el programa finaliza.

Cada archivo se diseña en base a **registros**, siendo el **registro** la **unidad mínima de información transferible** entre el archivo y la memoria RAM.

---

## 2. Organización de Archivos

La **organización de un archivo** define la manera en que los registros se distribuyen físicamente dentro del almacenamiento secundario.  
Existen tres tipos principales:

### A. Organización Secuencial
- Los registros se almacenan **consecutivamente**, en el orden en que se ingresan.  
- Se **graban y recuperan en el mismo orden**.
- Es el método más simple, pero **limita el acceso directo** a los datos.

### B. Organización Indexada o Directa
- El orden físico **no corresponde al orden lógico** de los registros.  
- Permite acceder directamente a un registro por **posición o clave**, sin recorrer los anteriores.
- Admite **búsqueda rápida y acceso aleatorio** a los datos.

### C. Organización Particionada o Secuencial Indexada
- Combina características de las dos anteriores.
- Los registros se agrupan y cada grupo se accede directamente (por posición o clave).
- Dentro de cada grupo, los registros se recorren secuencialmente.
- Ejemplo: una **guía telefónica**, donde se busca la letra inicial (acceso directo) y luego se avanza secuencialmente dentro del grupo.

---

## 3. Técnicas de Acceso a Archivos

Las **técnicas de acceso** definen el método mediante el cual los datos de un archivo son recuperados o manipulados.

### A. Acceso Secuencial
- Permite acceder a los registros **uno tras otro**, sin posibilidad de saltar.  
- Todo archivo **secuencial** se accede mediante esta técnica.  
- **Desventaja:** No se puede retroceder ni modificar un registro en el lugar; por lo tanto, las operaciones de actualización o eliminación requieren la creación de un **archivo auxiliar** que combine los datos originales con las modificaciones.

### B. Acceso Directo (Indexado)
- Permite leer o grabar un registro **por clave o índice**, sin necesidad de recorrer los anteriores.
- Los archivos de organización directa admiten tanto **acceso directo** como **acceso secuencial**.

#### Operaciones Específicas del Acceso Directo (AOD)
El acceso directo permite manipular registros directamente en su ubicación física mediante las siguientes operaciones:

| Operación | Descripción |
|------------|--------------|
| **Ir (archivo, nro_registro)** | Posiciona el puntero en un registro específico (indexado desde 0) sin procesarlo. |
| **Posición (archivo)** | Retorna el número del registro actual (posición corriente). |
| **Tamaño (archivo)** | Retorna la cantidad total de registros del archivo. |

##### Ejemplo de Manejo del AOD (Modificación)
1. Abrir el archivo en **modo entrada/salida**.  
2. Leer el registro y obtener su posición con `Posición(archivo)`.  
3. Reposicionar el puntero una posición antes del registro leído con `Ir(archivo, i - 1)`.  
4. Usar `Grabar` para sobrescribir el registro modificado en esa misma posición física.

---

## 4. Métodos de Búsqueda para Conjuntos Grandes

Cuando el conjunto de datos es grande, se aplican **métodos de búsqueda eficientes**, siendo la **búsqueda binaria (dicotómica o bipartita)** la más destacada.

### A. Principio "Divide y Vencerás"
Este método se basa en dividir el conjunto en dos partes y continuar la búsqueda únicamente sobre la mitad que puede contener el dato.  
**Requiere que los datos estén previamente ordenados.**

### B. Mecanismo de Búsqueda
1. Dividir el conjunto en su **elemento central**.  
2. Comparar el valor buscado con dicho elemento.  
3. Si el valor buscado es:
   - **Mayor**, descartar la primera mitad.
   - **Menor**, descartar la segunda mitad.
4. Repetir el proceso sobre la mitad seleccionada hasta encontrar el dato o agotar las subdivisiones.

### C. Eficiencia
- El acceso secuencial es **ineficiente** para conjuntos grandes (requiere hasta *N* comparaciones).  
- La **búsqueda binaria** tiene complejidad **O(log₂ N)**, siendo mucho más rápida.  
- Para grandes volúmenes de datos ordenados, la búsqueda binaria es el método más eficiente.

---

## 5. Tablas Hash

Las **tablas hash** son una estructura de datos que permite un **acceso directo y eficiente** a registros mediante el uso de una **función hash**, que transforma una **clave** en una **dirección de almacenamiento** o **índice** dentro del archivo.

### A. Concepto General
- Cada registro posee una **clave única** (por ejemplo, un DNI o un ID).  
- Una **función hash** convierte esa clave en una **posición física** en el archivo o tabla.  
- Permite ubicar un registro **sin necesidad de recorrer ni ordenar** todos los datos.

### B. Componentes Principales
| Componente | Descripción |
|-------------|--------------|
| **Clave** | Identificador único del registro. |
| **Función Hash (h)** | Calcula la dirección o índice donde se almacenará el registro. |
| **Tabla Hash** | Estructura que almacena los registros según la dirección generada por la función hash. |

### C. Colisiones
Dos claves diferentes pueden producir la **misma dirección hash**.  
A este fenómeno se lo llama **colisión** y se resuelve mediante distintos métodos:

#### Métodos de Resolución
- **Encadenamiento (Chaining):** Cada posición de la tabla almacena una lista enlazada con los elementos que comparten la misma dirección.  
- **Dirección Abierta (Open Addressing):** Se busca otra posición disponible dentro de la tabla mediante un desplazamiento controlado (lineal, cuadrático, etc.).  
- **Rehashing:** Se aplica una nueva función hash para recalcular la dirección.

### D. Ventajas
- Acceso **casi constante** a los registros: **O(1)** promedio.  
- Ideal para grandes volúmenes de datos con consultas frecuentes.  
- Evita recorridos secuenciales o búsquedas binarias.

### E. Desventajas
- Posibles **colisiones**, que afectan el rendimiento.  
- Requiere una **función hash adecuada** y una **distribución uniforme** de claves.  
- El tamaño de la tabla debe planificarse según la cantidad de registros esperados.

---

## 6. Conclusión

Las **estructuras de archivos** garantizan la **persistencia de datos fuera de la memoria principal**, posibilitando su almacenamiento y recuperación a largo plazo.  
La **organización secuencial**, la **directa/indexada** y las **tablas hash** determinan el modo de acceso (lineal, aleatorio o directo), mientras que las técnicas como la **búsqueda binaria** optimizan la localización de datos en grandes volúmenes.  

En definitiva, la eficiencia de un sistema depende de elegir la **organización y método de acceso** más apropiados según el tipo de procesamiento requerido.