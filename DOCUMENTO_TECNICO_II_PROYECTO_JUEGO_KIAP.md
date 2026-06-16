Documento técnico del II Proyecto de Programación 2

Introducción
El proyecto consiste en una simulación de combate desarrollada en C++, donde un jugador debe enfrentarse a diferentes enemigos a lo largo de varias rondas. La solución fue diseñada siguiendo los principios de Programación Orientada a Objetos, buscando mantener una estructura modular, reutilizable y fácil de extender.
Durante el desarrollo se tomaron diversas decisiones de diseño para separar responsabilidades, facilitar el mantenimiento del código y permitir la incorporación de nuevas funcionalidades sin modificar la lógica principal del sistema.

-Uso de herencia para representar personajes:
Una de las principales decisiones fue crear una clase abstracta llamada Character, encargada de representar las características comunes de cualquier participante de una pelea.
Esta clase contiene atributos compartidos como:
Nombre.
Género.
Vida.
Daño.
Estado de vida.
Movimientos disponibles.
Zonas corporales.
A partir de esta clase se derivan:
Player
Enemy
De esta forma se evita duplicar código y se centraliza la lógica común de todos los personajes.
Además, la clase posee métodos virtuales puros como:
virtual string getName() = 0;
virtual bool heal(int amount) = 0;

Lo que obliga a cada clase derivada a implementar su propio comportamiento.

-Aplicación de polimorfismo:
El uso de punteros del tipo Character* permite trabajar con jugadores y enemigos de forma uniforme.
Por ejemplo, la simulación almacena los participantes utilizando referencias al tipo base:
Character* player1;
Character* actualEnemy;

Gracias al polimorfismo, la simulación puede invocar métodos como:
heal()
show()
getName()

Sin necesidad de conocer si se trata de un jugador o de un enemigo. Esto facilita la extensibilidad del sistema para futuros tipos de personajes.

-Separación de responsabilidades: 
El proyecto divide la lógica en varias clases especializadas.
Character:
Gestiona los atributos generales de los personajes.
Player:
Gestiona elementos exclusivos del jugador:
Experiencia.
Curación.
Compra de movimientos.

Enemy: 
Representa enemigos de diferentes dificultades.
Movement: 
Representa cada movimiento de combate y almacena:
Daño.
Dificultad.
Extremidad utilizada.
Zona impactada.
Costo.
Fight: 
Se encarga exclusivamente de la lógica de ejecución de un golpe.
Simulation: 
Controla el flujo general del juego:
Menús.
Rondas.
Tienda.

Selección de enemigos: 
Inicio y finalización de la simulación.
Save: 
Gestiona el almacenamiento de datos y la bitácora de combates.
Esta distribución reduce el acoplamiento entre componentes y mejora la mantenibilidad.

-Uso del patrón Factory:
En el proyecto se implementa el patrón Factory para la creación de objetos complejos cargados desde archivos.
EnemyFactory: 
Se encarga de:
Crear enemigos.
Asignarles movimientos automáticamente.
Clasificarlos según dificultad.

MovementsFactory: 
Carga los movimientos desde archivos de texto y crea los objetos correspondientes.
ZonesFactory: 
Construye las zonas corporales a partir de archivos externos.
Además, que el uso de fábricas evita que la lógica de creación se encuentre dispersa por el programa. Y facilita agregar nuevos enemigos o movimientos sin modificar la simulación.

-Uso del patrón Strategy: 
El comportamiento de los ataques se modela mediante objetos de tipo Movement. Cada movimiento representa una forma diferente de ejecutar una acción durante el combate, ya que posee:
Daño distinto.
Dificultad distinta.
Costos distintos.
Restricciones de uso distintas.
Desde el punto de vista conceptual, cada movimiento actúa como una estrategia diferente para atacar al enemigo.
Aunque no se implementa formalmente mediante una jerarquía de estrategias, sí existe una aproximación al patrón Strategy al encapsular diferentes comportamientos de ataque dentro de objetos independientes.

-Uso del patrón Template Method: 
La clase abstracta Character define una estructura común para todos los personajes del juego.
Las clases derivadas (Player y Enemy) implementan comportamientos específicos mediante métodos virtuales y virtuales puros. Esto genera una estructura donde la clase base define qué operaciones deben existir y las clases hijas determinan cómo se ejecutan.
Ejemplos:
virtual string getName() = 0;
virtual bool heal(int amount) = 0;
virtual void show() = 0;
Esta organización sigue la filosofía del patrón Template Method, ya que establece un marco general de funcionamiento que debe ser completado por las clases derivadas.

-Uso del patrón Composite:
La composición es una decisión importante utilizada en todo el proyecto.
Por ejemplo:
Un Character posee una colección de movimientos.
Un Character posee una colección de zonas corporales.
Una Fight utiliza personajes y movimientos para ejecutar el combate.
Una Simulation administra peleas, enemigos y jugadores.
Esta relación "tiene un" que permite construir objetos complejos a partir de otros más pequeños y reutilizables.

-Uso de archivos de textos:
Una decisión importante fue almacenar gran parte de la información del sistema en archivos de texto:
Enemigos.
Personaje principal.
Movimientos.
Zonas corporales.
Esto aporta varias ventajas:
Permite modificar datos sin recompilar.
Facilita las pruebas.
Mejora la flexibilidad del sistema.
Separa los datos de la lógica de negocio.
La simulación construye los objetos leyendo estos archivos durante la ejecución.
Sistema de movimientos basado en probabilidad
Cada movimiento posee un atributo de dificultad.
Cuando un personaje intenta ejecutar un ataque, el método: makeMove() genera un número aleatorio para determinar si el golpe tiene éxito. Esto introduce incertidumbre y hace que cada combate sea diferente. La mecánica evita que las peleas se vuelvan completamente predecibles.

-Modelado de zonas corporales: 
- Los personajes poseen diferentes zonas corporales almacenadas mediante objetos BodyZone.
- Cada movimiento requiere una extremidad específica para ejecutarse.
- Antes de realizar un golpe se valida que:
- El personaje posea la extremidad.
- La extremidad se encuentre disponible.
- El movimiento pueda ejecutarse correctamente.
Esta decisión agrega realismo a la simulación y permite controlar el desgaste de las extremidades durante la pelea.

-Sistema de progresión del jugador:
El personaje principal cuenta con experiencia acumulable. Después de ganar combates obtiene puntos que posteriormente puede utilizar para adquirir nuevos movimientos. Esta mecánica introduce un sistema de progreso que recompensa el desempeño del jugador. Además, genera una diferencia clara entre el jugador y los enemigos.

-Serialización y persistencia:
El proyecto implementa una interfaz llamada Serialize. Esta interfaz obliga a las clases que la implementan a definir string serialize(); Gracias a esto los objetos pueden convertirse fácilmente en texto para ser almacenados en archivos.
La clase Save utiliza esta funcionalidad para guardar:
Información del jugador.
Información de enemigos.
Bitácoras de combate: 
Esta decisión desacopla la lógica de almacenamiento de la lógica de los personajes.

-Manejo de excepciones:
El sistema incorpora validaciones y excepciones para detectar errores durante la carga de datos.
Por ejemplo:
Archivos inexistentes.
Archivos vacíos.
Datos duplicados.
Información inválida.
Esto evita que la simulación continúe en estados inconsistentes y mejora la robustez del programa.

-Uso de aleatoriedad: 
La simulación utiliza generadores de números aleatorios para:
Seleccionar enemigos.
Determinar el éxito de movimientos.
Variar el comportamiento de los combates.
Esta decisión permite que cada partida sea diferente y aumenta la rejugabilidad (capacidad que tiene un videojuego o simulación para seguir siendo interesante después de haber sido jugado una o varias veces) del sistema.




Conclusión
El diseño del proyecto se basa en los principios fundamentales de Programación Orientada a Objetos. Se emplearon conceptos como herencia, polimorfismo, encapsulamiento, composición y patrones de diseño para construir una simulación modular y extensible.
Las decisiones tomadas permiten separar adecuadamente las responsabilidades, reutilizar código y facilitar futuras ampliaciones del sistema, como la incorporación de nuevos tipos de personajes, movimientos, zonas corporales o mecánicas de combate sin afectar significativamente la estructura existente.
