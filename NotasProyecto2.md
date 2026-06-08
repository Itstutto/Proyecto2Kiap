# Notas del Proyecto 2

## Diseño de Clases

```text
Character
├── Player
└── Enemigo (categorías 1, 2 y 3)
```

- Dependiendo del género, se puede utilizar el patrón **Singleton** (pendiente de analizar).
- Implementar la mecánica de hacer enojar al oponente.
- Avisar cuando se utilicen objetos; esto incrementa el daño causado.
- Crear un **Factory** para generar los tipos de movimiento.
- Dependiendo de la zone de impacto, la potencia de los golpes se verá afectada.
- **Extremidad** y **Zona de Impacto** utilizarán los mismos datos.

## Singleton

- Debe contener las zonas superiores e inferiores.
- Utilizar archivos de configuración con las zonas.
- Cargar estos datos al inicio de la simulación.

## Decorador

- Equipamiento de protecciones.
- Objetos para daño o rendimiento.
  - También puede resolverse mediante **templates** o **polimorfismo**.

---

# Pendientes para el Martes 7

- Crear la clase `Enemigo` y asegurar su instancia.
- Revisar patrones de diseño y consultar cuáles podrían utilizarse.

------------------------------------------
En Golpes, se le asignará un puntaje, dependiendo de que tipo se golpe sea.
Strategy lo podemos usar con potenciadores del tipo de golpe, o de defensa.
--(por ejemplo, peto defectuoso: no marca punto, bebida energética: marca el doble de puntos, etc.)

-Hacer 2 archivos de texto, cada uno tiene que llenarse con zonas del cuerpo, uno para zone inferior y otra para zone superior
en cada linea debe ir una zone diferente

-Hacer que al final de la pelea, si gana se le dan unos puntos al personaje, y con esos puntos puede canjear nuevos movements,
se le hace tabla para saber la información de cada personaje, como sus movements, puntos, etc.

RealizarGolpe (clase por crear, que hará toda la lógica para saber si el golpe se dio o no)



-Hacer las excepciones en todos los objetos que se crean con archivos(personajes, zonas, movements) revisar sus constructores
-Llenar los archivos de textos: 
-Movimientos: Todos
Enemigos: 5 de cada difficulty de enemigos(en zonas inferiores y superiores)
Character Principal : 1

-Separar los metodos de simulacion en clases(puede ser) 
-Ponerle un atributo al personaje principal, recuperar, y other atributo que tenga guardado la experiencia 
-Posibilidad de que el enemigo se cure

-Agregar costo a los movements en el archivo 


