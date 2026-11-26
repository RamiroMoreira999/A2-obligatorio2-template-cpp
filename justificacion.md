# Justificación de órdenes — Obligatorio 2

## Ejercicio 6
- Restricciones: tiempo O(N), espacio O(N).
- Justificación: los números de las placas están acotados (0 a 1000), así que contamos
  cuántas placas hay de cada número en un arreglo de 1001 posiciones, en una pasada de
  O(N). `largoSolucion` y `cartelMax` recorren a lo sumo 1001 posiciones, que es
  constante. El `while` que arma el cartel en cada vuelta coloca un par (a lo sumo N/2
  veces) o baja al número siguiente (a lo sumo 1001 veces), así que es O(N + 1001) = O(N).
  No se ordena: un heap o un sort serían O(N log N). Espacio: el arreglo de conteo (1001,
  constante) y el arreglo `ret` con el cartel (a lo sumo N), O(N).

## Ejercicio 7
- Restricciones: tiempo O(N log N), espacio O(N).
- Justificación: usamos merge sort. Cada llamada divide el tramo a la mitad, así que hay
  log N niveles de recursión. En cada nivel, contar las remontadas cruzadas es O(N) porque
  el índice `j` de la mitad derecha nunca retrocede (las mitades están ordenadas), y el
  merge también es O(N). Total: O(N log N). Espacio: el arreglo de llegada y un único
  arreglo auxiliar de tamaño N que se reutiliza en todas las llamadas, más la pila de
  recursión de profundidad log N: O(N). El resultado se guarda en 64 bits porque puede
  superar el rango de un int.

## Ejercicio 8
- Restricciones: tiempo y espacio O(N·W·L0·L1·L2·L3).
- Justificación: tabulación (bottom-up) con una tabla
  tab[i][w][a][c][b][v] de (N+1)·(W+1)·(L0+1)·(L1+1)·(L2+1)·(L3+1) casillas, una
  dimensión para los productos, otra para la capacidad y una por cada cupo de categoría.
  Cada casilla se calcula en O(1) comparando dos opciones (comprar o no el producto i),
  usando solo la fila i-1. Tiempo y espacio: O(N·W·L0·L1·L2·L3).

## Ejercicio 9
- Restricciones: tiempo O(K²), espacio O(K²).
- Justificación: memoización sobre el estado (ronda, ventaja, si bailó en el tiro
  anterior). La ronda va de 0 a K y la ventaja de 0 a K, y el último valor es 0 o 1, así
  que hay O(K·K·2) = O(K²) estados. Cada estado se calcula una sola vez, en O(1) (dos
  opciones: bailar o no), y después se lee del memo. Inicializar el memo también es
  O(K²). Espacio: el memo de O(K²) más la pila de recursión de profundidad K.

## Ejercicio 10
- Sin restricciones de órdenes (la letra solo pide backtracking con podas).
- Justificación: backtracking que asigna un dígito a cada letra distinta (a lo sumo 10),
  así que en el peor caso es exponencial (como mucho 10! asignaciones). Podas:
  1. letras distintas usan dígitos distintos (`usado`);
  2. la primera letra de una palabra de más de una letra no puede ser 0 (`noCero`);
  3. después de cada asignación se verifican las columnas completas desde las unidades
     con el acarreo, y si una no cierra se corta esa rama (`columnasOk`);
  4. si un sumando es más largo que el resultado, el acertijo es imposible sin buscar.
  Las letras se asignan de derecha a izquierda para que las columnas de las unidades se
  completen primero y la poda 3 actúe lo antes posible. No se corta en la primera
  solución: se recorren todas y se guarda la menor según el orden de la letra.