# Manejo y Clasificación de Errores en C

## Descripción General

En **C**, el manejo de errores no dispone de mecanismos como `try/catch` de C++ o Java.  
Por ello, la corrección y control de errores se realiza mediante:

- **Códigos de retorno de funciones**  
- **Señales (`signal`)**  
- **Variable global `errno`**  

El manejo correcto de errores permite programas más **robustos**, facilita la depuración y evita fallos críticos.

---

## 1. Clasificación de Errores por Fase de Detección

| Tipo de Error | Causa | Ejemplo | Detección |
|---------------|-------|---------|-----------|
| **Compilación (Sintácticos/Ortográficos)** | Fallos al escribir código | Palabra clave mal escrita, puntuación omitida | Detectados al compilar |
| **Tiempo de Ejecución (Runtime)** | Operaciones imposibles | División por cero, acceso a memoria no válida | Solo al ejecutar |
| **Lógicos** | Código correcto sintácticamente pero con resultado inesperado | Olvidar inicializar variable | Difíciles de detectar; requieren pruebas |

---

## 2. Clasificación de Errores por Gravedad

| Gravedad | Descripción | Ejemplos Comunes |
|----------|------------|----------------|
| **Críticos** | Impiden correcta ejecución | División por cero, punteros mal inicializados, desbordamiento de pila, bucles infinitos |
| **No graves** | Afectan ejecución pero no siempre | Variables no inicializadas, advertencias de compilación |
| **Irrelevantes** | Solo estética, no ejecución | Errores ortográficos en mensajes |

---

## 3. Métodos de Manejo de Errores en C

- **Códigos de retorno:** Las funciones devuelven un valor indicando éxito o error.  
- **`errno`:** Variable global que indica errores en funciones de librería estándar.  
- **Señales (`signal`):** Captura errores en tiempo de ejecución, como división por cero o interrupciones externas.  

> Nota: C no tiene soporte nativo para excepciones (`try/catch`) como otros lenguajes.

---

## 4. Verificación y Estrategias de Corrección

- **Verificación:** Validar que un algoritmo cumple la especificación.  
- **Corrección Parcial:** Si termina, garantiza que produce el resultado correcto.  
- **Corrección Total:** Garantiza terminación y cumplimiento para cualquier dato válido.  
- **Manejo Preventivo:** Uso de estructuras de control (decisión y repetición) para validar datos antes de operaciones críticas.  
- **Archivos:** 
  - Secuenciales (AOS): requieren archivos auxiliares para modificaciones.  
  - Acceso Directo (AOD): permiten modificación in situ con posicionamiento y sobrescritura lógica.  

---

## 5. Conclusión

El manejo de errores es esencial para:
- Garantizar que los programas se ejecuten correctamente  
- Detectar errores tempranos en compilación o ejecución  
- Prevenir fallos críticos y bucles infinitos  
- Facilitar la depuración y el mantenimiento  

Una estrategia de programación robusta combina:
- Clasificación clara de errores  
- Prevención mediante estructuras de control  
- Verificación sistemática mediante pruebas  

> La correcta clasificación y manejo de errores asegura software confiable, eficiente y mantenible.