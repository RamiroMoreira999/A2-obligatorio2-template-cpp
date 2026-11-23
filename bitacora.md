# Bitácora — Obligatorio 2

**Integrantes:** Nombre Apellido (Nº estudiante), Nombre Apellido (Nº estudiante)

> **Instrucciones** (borrar esta sección antes de entregar): agregar una entrada por
> cada día trabajado, indicando la fecha y quién trabajó (un integrante o "En conjunto").
> Registrar el proceso real: ideas exploradas, decisiones y su justificación, partes de
> implementaciones, bugs encontrados y cómo se corrigieron, resultados de pruebas y dudas
> abiertas. Si se usó IA ese día, indicar herramienta, consulta y qué se hizo con la
> respuesta. Una bitácora escrita íntegramente el día de la entrega implica pérdida de puntos.

## AAAA-MM-DD — Nombre
- Ejemplo: Leí la letra del ejercicio 6. Primera idea: ... pero la restricción de
  complejidad pide ..., así que ...

## AAAA-MM-DD — En conjunto
- Ejemplo: Implementamos ... Bug: ... Lo corregimos ...
- Pasan los casos de prueba 1 a 4 del ejercicio 6.

## 2026-11-13 - Ramiro Moreira
-Hoy solo cree el repositorio y fijamos una fecha con mi compañero de grupo para empezar con el ejercicio uno y quedamos para hacerlo pasado mañana.

## 2026-11-15 - En conjunto
- Hoy hicimos el ejercicio 6, respecto a los del obligatorio anterior la verdad que no nos supuso una gran dificultad. Al principio lo relacionamos con un ejercicio de subsecuencias que habíamos trabajado en clase, por lo que intentamos pensarlo desde ese enfoque.
Para resolverlo, decidimos utilizar un arreglo de placas para contar las cantidad de placas con el mismo número. Después, aprovechamos esos valores para formar los pares, colocando los más grandes en los extremos y dejando el mayor sobrante para el centro. También creamos dos funciones auxiliares: largoSolucion() para calcular el tamaño del cartel y cartelMax() para encontrar la placa central.
Por otro lado, acordamos organizar todos los ejercicios de la misma manera: dejar el main en ejercicioX.cpp y guardar las funciones auxiliares en archivos separados dentro de la carpeta funciones, con nombres como auxEj6.cpp. Nos pareció una forma más prolija y clara de organizar el código. A su vez, también intentamos comenzar con el ejercicio 7, pero nos surgieron algunas dudas sobre cómo resolverlo. De todas formas, pudimos avanzar con la lectura de los datos en el main y la creación de las funciones auxiliares que pensamos utilizar. Dejamos pendiente continuar con la resolución del ejercicio. 

## 2026-11-16 - En conjunto
- Continuamos con el ejercicio 7. Sabíamos que por el orden temporal debíamos utilizar Merge Sort, pero nos costó encontrar cómo contar las remontadas cruzadas.
Finalmente, decidimos contar recursivamente las remontadas dentro de cada mitad y luego ordenar ambas de menor a mayor. Para contar las cruzadas, comparamos los corredores de la izquierda con los de la derecha, verificando si el dorsal del primero era mayor que el doble del segundo. Aprovechamos que estaban ordenadas para hacerlo con dos índices, evitando comparaciones innecesarias. Por último, unimos las mitades ordenadas y sumamos las remontadas.

## 2026-11-17 - En conjunto
- Empezamos con el 8 en clase pero nos mato la letra, tipo no entendiamos como teniamos que implementar el tab, en eso le preguntamos a fran y a fede de como implementarlo y nos dimos cuenta de que teniamos que usar una estrucura de 6 dimensiones, esto nos dejo re descolocados. Lo empezamos y lo dejamos baastante cerca de terminar pero no pudimos porque aun habian cosas que no nos cerraban de la letra. 

## 2026-11-18 - En conjunto
- Hoy terminamos el ejercicio 8. La verdad que nos costó bastante, pero al final nos dimos cuenta de que había una forma más sencilla de pensar la tabulación. En lugar de intentar manejar todas las dimensiones a la vez, pensamos que para cada producto teníamos dos opciones: comprarlo o no comprarlo, y quedarnos con la que diera mayor satisfacción.
Para implementarlo, utilizamos una tabla de seis dimensiones, donde guardamos la mejor satisfacción según la cantidad de productos considerados, el peso disponible y los cupos de cada categoría. Si comprábamos un producto, restábamos su peso y un cupo de su categoría; si no, manteníamos los valores anteriores. Finalmente, comparamos ambas opciones y guardamos la mejor. Una vez que lo pensamos de esta manera, nos resultó mucho más fácil terminarlo.

## 2026-11-22- En conjunto
- Hoy hicimos el ejercicio 9. La verdad es que al principio, cuando leímos la letra, no habíamos entendido casi nada, pero después de pedirle a nuestro buen amigo gepeto que nos la explicara, el ejercicio nos resultó bastante más fácil. 
Para resolverlo, usamos la misma estructura que veníamos trabajando en clase para los ejercicios de memoización: una función que inicializa el memo y otra que hace la recursión. La idea fue pensar qué pasaba si el arquero bailaba o no en cada ronda y quedarnos con la opción que diera más likes, teniendo en cuenta la ventaja que llevábamos y si había bailado en la ronda anterior.
Una cosa que no sabíamos era cómo pasar nuestro memo de tres dimensiones como parámetro a la otra función auxiliar. Entonces, le preguntamos a ChatGPT, que nos explicó cómo hacerlo y además nos recomendó usar static para evitar posibles problemas de memoria por el tamaño de la matriz.