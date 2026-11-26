# Declaración de autoría — Obligatorio 2

> **Instrucciones** (borrar esta sección antes de entregar): declarar para cada ejercicio
> las fuentes utilizadas: código discutido o desarrollado en clase, recursos web (con URL)
> y uso de herramientas de IA generativa (herramienta, consulta y uso dado, según los
> lineamientos de Uso de IA de la letra). Si no se usaron fuentes externas, indicarlo
> explícitamente. Los fragmentos de terceros o generados por IA deben además señalarse
> con comentarios en el código fuente. La omisión de fuentes puede considerarse plagio.

## Ejercicio 6
- Implementación propia: arreglo de conteo de placas, funciones `largoSolucion` y
  `cartelMax`, y armado del cartel desde los dos extremos con índices `izq`/`der`.
- Usamos Claude (Anthropic) para analizar la letra y discutir el enfoque greedy
  (pares de mayor a menor en los extremos, el mayor sobrante al centro) y por qué
  un arreglo de conteo permite O(N) sin ordenar. También lo usamos para revisar
  nuestro código y probarlo con los casos de la letra (ver entradas del 2026-11-13
  y 2026-11-16 en la bitácora).

## Ejercicio 7
- Planteo con merge sort (dividir y conquistar) basado en lo visto en clase.
- El conteo de remontadas cruzadas con dos índices (`comparo`) y el merge
  (`mergeComparo`) se completaron con ayuda de Claude (Anthropic): nos explicó cómo
  contar los pares cruzados antes de mezclar, aprovechando que las dos mitades vuelven
  ordenadas de la recursión, y nos propuso el código, que adaptamos y probamos con los
  casos de la letra (ver entrada del 2026-11-16 en la bitácora).
- La lectura de la entrada y la estructura recursiva inicial (caso base y división en
  mitades) son propias.

## Ejercicio 8
- Basado en la mochila 0/1 con tabulación vista en clase.
- La idea de agregar una dimensión por categoría a la tabla surgió de consultas en clase
  con los docentes (ver entrada del 2026-11-17 en la bitácora).
- El código de `mejorCompra` (tabla de 6 dimensiones, decisión comprar / no comprar y el
  arreglo `cupo` para descontar solo la categoría del producto) fue generado con Claude
  (Anthropic) a partir de nuestra versión de la mochila 0/1, y lo revisamos, adaptamos y
  probamos con los casos de la letra. También usamos Claude para entender por qué hacen
  falta tantas dimensiones y por qué el `for` de la capacidad puede ir desde 0 cuando se
  guarda una fila por producto.

## Ejercicio 9
- Estructura de memoización (función que inicializa el memo y función recursiva) basada
  en lo visto en clase.
- Usamos ChatGPT (OpenAI) para que nos explicara la letra del ejercicio, para saber cómo
  pasar el memo de tres dimensiones como parámetro a la función recursiva, y por su
  recomendación declaramos el memo como `static` por su tamaño (ver entrada del
  2026-11-22 en la bitácora).
- El planteo de los estados (ronda, ventaja, si bailó antes) y la recursión son propios.


## Ejercicio 10
- El enfoque (asignar dígitos letra por letra, ordenando las letras de derecha a
  izquierda, y verificar en cada paso las columnas completas de la suma con el acarreo)
  lo discutimos con Claude (Anthropic).
- El código (`auxEj10.cpp`) fue generado con Claude a partir de ese enfoque; lo
  adaptamos para usar solo lo visto en el curso (int64_t, sin break/continue), lo
  revisamos y lo probamos con los casos de la letra (ver entrada del 2026-11-24 en la
  bitácora).

